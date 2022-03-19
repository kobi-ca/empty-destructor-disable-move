#include <memory>

namespace Ex1 {
    struct Test {};
    // Test t(in); <-- copy constructor
    void f(Test t) {}
}

namespace Ex2 {
    struct Test {
        std::unique_ptr<int> i_;
    };
    // Test t(&& in); <-- move constructor
    void f(Test t) {}
}

namespace Ex2_1 {
    struct Test {
        std::unique_ptr<int> i_;
    };
    void f(Test t) {}
}

namespace Ex3 {
    struct Test {
        std::unique_ptr<int> i_;
        ~Test() {}
    };
    void f(Test t) {}
}

namespace Ex4 {
    struct Test {
        std::unique_ptr<int> i_;
        Test(const Test&) = default;
        Test() = default;
        ~Test() {}
    };
    void f(Test t) {}
}

namespace Ex5 {
    struct Test {
        std::unique_ptr<int> i_;
        Test(const Test&)  {}
        Test() = default;
        ~Test() {}
    };
    void f(Test t) {}
}

namespace Ex6 {
    struct Test {
        std::unique_ptr<int> i_;
        ~Test() = default;
    };
    void f(Test t) {}
}

namespace Ex7 {
    struct Test {
        std::unique_ptr<int> i_;
        Test(Test&&) = default;
        Test() = default; // needed since we are bring _a_ ctor (even if this is a =default one)
        ~Test() = default;
    };
    void f(Test t) {}
}

int main()
{
    {
        Ex1::Test t;
        f(t);
    }

    {
        Ex2::Test t;
        f(std::move(t));
    }

    {
        Ex2_1::Test t;
        f(t); // will not work, no copy ctor
    }

    {
        Ex3::Test t;
        f(t);   // <-- does not work
                // Copy ctor is implicitly deleted, because of unique_ptr<>
    }

    {
        Ex3::Test t;
        f(std::move(t));   // <-- does not work
        // Even Move! ctor is implicitly deleted, because of unique_ptr<>
    }

    {
        Ex4::Test t;
        f(t);   // <-- does not work
        // Copy ctor is implicitly deleted, because of unique_ptr<>
    }

    {
        Ex5::Test t;
        f(t);   // yes, I can make this work now.
    }

    {
        Ex6::Test t;
        f(std::move(t));   // even = default will delete the move/copy
    }

    {
        Ex7::Test t;
        f(std::move(t));   // yes, this works if I bring =default of && ctor
    }
}