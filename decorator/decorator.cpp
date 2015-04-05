#include <iostream>
#include <string>

using namespace std;

struct BeverageBase {
  virtual ~BeverageBase(){}

  virtual auto name() -> string = 0; 
  virtual auto price() -> int = 0;
};

//Beverages
struct BlackTea: public BeverageBase {
  virtual auto name() -> string { return "Black Tea"; }
  virtual auto price() -> int { return 20; }
};


//Ingredients
struct MilkDecorator: public BeverageBase {
  MilkDecorator (BeverageBase *base): 
    base(base) 
  {}

  virtual auto price() -> int {
    return (base->price() + 5);
  }

  virtual auto name() -> string {
    return base->name().append(" + Milk");
  }

private:
  BeverageBase *base;
};

struct PearlDecorator: public BeverageBase {
  PearlDecorator (BeverageBase *base): 
    base(base) 
  {}

  virtual auto price() -> int {
    return (base->price() + 10);
  }

  virtual auto name() -> string {
    return base->name().append(" + Pearl");
  }

private:
  BeverageBase *base;
};


// Test
int main() {

  //Pure black tea
  BlackTea blackTea;  
  cout << "Price of " << blackTea.name() << ": " << blackTea.price() << endl;

  //Milk tea (black tea + milk)
  MilkDecorator milkTea(&blackTea);  
  cout << "Price of " << milkTea.name() << ": " << milkTea.price() << endl;

  //Pearl tea (black tea + pearl)
  PearlDecorator pearlTea(&blackTea);  
  cout << "Price of " << pearlTea.name() << ": " << pearlTea.price() << endl;

  //Pearl milk tea (black tea + pearl + milk)
  MilkDecorator pearlMilkTea(&pearlTea);
  cout << "Price of " << pearlMilkTea.name() << ": " << pearlMilkTea.price() << endl;

  return 0;
}

