#include "Board.hpp"

namespace pandemic{
  bool Board::is_clean(){
    return false;
  }
  int & Board::operator[]( City c ){
    return this->cube[c];
  }
  void Board::remove_cures(){

  }
  ostream& operator<<(ostream& os,Board const & b){
    return os;
  }
}
