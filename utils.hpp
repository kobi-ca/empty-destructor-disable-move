//
// Created by kobi on 3/19/22.
//

#ifndef EMPTY_DESTRUCTOR_DISABLE_MOVE_UTILS_HPP
#define EMPTY_DESTRUCTOR_DISABLE_MOVE_UTILS_HPP

#include <vector>

namespace somename {

// header is included all over the place, utils is a common
// class that is being used a lot.
class utils {
public:
  // ...
  ~utils();
private:
  std::vector<int> vec_;
};
}

#endif // EMPTY_DESTRUCTOR_DISABLE_MOVE_UTILS_HPP
