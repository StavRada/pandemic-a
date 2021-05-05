#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic{
  class Player{
    private:
      Board b_;
      City c_;
      string type_player;
    public:
      //constractur

      Player(Board b,City c,string type) : b_(b),c_(c),type_player(type){}

      //function

      Player& drive(City c_);
      virtual Player& fly_direct(City c_);
      Player& fly_charter(City c_);
      Player& fly_shuttle(City c_);
      virtual Player& build();
      virtual Player& discover_cure(Color c_);
      virtual Player& treat(City c_);
      string role(){return type_player;}
      Player& take_card(City c_);
  };
}
