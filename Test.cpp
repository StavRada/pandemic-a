
#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include <vector>
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include <iostream>
#include "doctest.h"

using namespace std;

using namespace pandemic;


TEST_CASE("check roles Scientist and OperationsExpert"){
Board b;
Scientist dana(b,City::HongKong,3);
OperationsExpert mike(b,City::Washington);

CHECK(dana.role()=="Scientist");
CHECK(mike.role()=="OperationsExpert");

CHECK_NOTHROW(mike.take_card(City::Miami));

CHECK_NOTHROW(mike.fly_direct(City::Miami));

CHECK_THROWS(mike.fly_direct(City::Chicago));

CHECK_NOTHROW(mike.build());

CHECK_NOTHROW(dana.take_card(City::Miami)
.take_card(City::Chicago)
.take_card(City::Karachi));

CHECK_NOTHROW(dana.discover_cure(Color::Yellow)
.discover_cure(Color::Blue)
.discover_cure(Color::Black));

CHECK_NOTHROW(dana.build());
CHECK_NOTHROW(dana.fly_shuttle(City::Miami));
}

TEST_CASE("check roles Researcher and Dispatcher"){
  Board b;
  Researcher niki(b,City::Atlanta);
  Dispatcher leo(b,City::Atlanta);

  CHECK(niki.role()=="Researcher");
  CHECK(leo.role()=="Dispatcher");

  CHECK_NOTHROW(niki.take_card(City::Miami)
  .take_card(City::MexicoCity));

  CHECK_NOTHROW(leo.take_card(City::Miami)
  .take_card(City::MexicoCity));

  CHECK_NOTHROW(niki.drive(City::Miami));
  CHECK_THROWS(leo.drive(City::MexicoCity));

  CHECK_NOTHROW(niki.build());
  CHECK_NOTHROW(leo.build());
  CHECK_NOTHROW(leo.fly_direct(City::MexicoCity));
  CHECK_NOTHROW(leo.build());
}

TEST_CASE("check roles Medic and Virologist"){
  Board b;
  Medic wil(b,City::Paris);
  Virologist ben(b,City::Istanbul);

  CHECK(wil.role()=="Medic");
  CHECK(ben.role()=="Virologist");

  CHECK_NOTHROW(wil.take_card(City::Delhi)
  .take_card(City::Mumbai)
  .take_card(City::Bangkok));
   b[City::Delhi] = 7;
   b[City::Mumbai] = 5;
   b[City::Bangkok] = 3;
   
  CHECK_NOTHROW(wil.fly_charter(City::Delhi));
  CHECK_NOTHROW(wil.treat(City::Delhi));
  CHECK_NOTHROW(b[City::Delhi]=0);
  CHECK_THROWS(wil.treat(City::Bangkok));
  CHECK_THROWS(b[City::Bangkok]=2);


  CHECK_NOTHROW(ben.take_card(City::Miami)
  .take_card(City::MexicoCity)
  .take_card(City::Lima));
   b[City::Miami] = 1;
   b[City::MexicoCity] = 6;
   b[City::Lima] = 5;

  CHECK_NOTHROW(ben.treat(City::Lima));
  CHECK_NOTHROW(b[City::Lima]=4);
  CHECK_NOTHROW(ben.treat(City::MexicoCity));
  CHECK_NOTHROW(b[City::MexicoCity]=5);
  CHECK_THROWS(ben.drive(City::Miami));

}
TEST_CASE("check roles GeneSplicer and FieldDoctor"){
  Board b;
  GeneSplicer dan(b,City::Chicago);
  FieldDoctor pol(b,City::Miami);

  CHECK(dan.role()=="GeneSplicer");
  CHECK(pol.role()=="FieldDoctor");
  
  CHECK_NOTHROW(dan.take_card(City::Miami)
  .take_card(City::NewYork)
  .take_card(City::LosAngeles)
  .take_card(City::Paris)
  .take_card(City::BuenosAires));

  CHECK_NOTHROW(dan.build());
  CHECK_NOTHROW(dan.discover_cure(Color::Black));
  CHECK_NOTHROW(dan.discover_cure(Color::Blue));


 CHECK_NOTHROW(pol.treat(City::Bogota));
 CHECK_NOTHROW(pol.treat(City::MexicoCity));
 CHECK_THROWS(pol.treat(City::Delhi));
 CHECK_THROWS(pol.treat(City::Riyadh));


}




