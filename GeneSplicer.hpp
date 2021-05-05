
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


namespace pandemic{
  class GeneSplicer: public Player{
    public:
      GeneSplicer(Board b,City c) : Player(b,c,"GeneSplicer"){}
      Player& discover_cure(Color c_) override;
  };
}
