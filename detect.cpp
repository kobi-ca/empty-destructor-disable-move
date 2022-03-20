//
// Created by kobi on 3/19/22.
//

// https://stackoverflow.com/questions/51901837/how-to-get-if-a-type-is-truly-move-constructible/51912859#51912859

#include <type_traits>
#include <utility>
#include <cstdio>

using namespace std;

struct S
{
  ~S();
  //S(S const&){}
  //S(S const&) = delete;
  //S(S&&) {}
  //S(S&&) = delete;
};

template<class P>
struct M
{
  // the moment both ctors are enabled from S, there is ambiguity
  // and the  S s(M<S>{}); aka is_constructible_v<S, M<S>>
  // will fail
  operator P const&();
  operator P&&();
};

constexpr bool has_cctor = is_copy_constructible_v<S>;
constexpr bool has_cctor1 = is_copy_constructible_v<S> && !is_constructible_v<S, M<S>>;
constexpr bool is_ctor_tmp = is_constructible_v<S, M<S>>;
constexpr bool has_only_mctor = is_move_constructible_v<S>;
constexpr bool has_mctor = is_move_constructible_v<S> && !is_constructible_v<S, M<S>>;

int main()
{
  printf("has_cctor = %d\n", has_cctor);
  printf("has_cctor1 = %d\n", has_cctor1);
  printf("is_ctor_tmp = %d\n", is_ctor_tmp);
  printf("has_only_mctor = %d\n", has_only_mctor);
  printf("has_mctor = %d\n", has_mctor);

//  S s(M<S>{});
//  return sizeof(s);
}
