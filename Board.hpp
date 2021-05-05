#pragma once

#include <map>
#include "City.hpp"

using namespace std;

namespace pandemic{
  class Board{
    private:
      map<City,int> cube;
    public:
      static bool is_clean();
      int & operator[]( City c );
      void remove_cures();
      friend ostream& operator<<(ostream& os,Board const & b);
  };
}
