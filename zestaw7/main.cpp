#include <iostream>
#include <vector>

using namespace std;

class Shape {
protected:
    virtual void draw() = 0;
public:
    virtual ~Shape() {
        cout << "Shape deleted" << endl;
    }
};

class Circle: public Shape {
public:
    virtual void draw() {
        cout << "It is a circle" << endl;
    }
    ~Circle() {
        cout << "Circle deleted" << endl;
    }
};

class Square: public Shape {
public:
    virtual void draw() {
        cout << "It is a square" << endl;
    }
    
    ~Square() {
        cout << "Square deleted" << endl;
    }
};

class Triangle: public Shape {
public:
    virtual void draw() {
        cout << "It is a triangle" << endl;
    }
    
    ~Triangle() {
        cout << "Triangle deleted" << endl;
    }
};

class Rodent {
public:
    virtual void whoAmI() = 0; //zeby klasa byla czysto abstrakcyjna
//    {
//        cout << "Unknown type of rodent" << endl;
//    }
    
    virtual ~Rodent() {
        cout << "Rodent deleted" << endl;
    }
};

class Mouse: public Rodent {
public:
    virtual void whoAmI() {
        cout << "I am a mouse" << endl;
    }
    ~Mouse() {
        cout << "Mouse deleted" << endl;
    }
};

class Gerbil: public Rodent {
public:
    virtual void whoAmI() {
        cout << "I am a gerbil" << endl;
    }
    
    ~Gerbil() {
        cout << "Gerbil deleted" << endl;
    }
};

class Hamster: public Rodent {
public:
    void whoAmI() {
        cout << "I am a hamster" << endl;
    }
    
    ~Hamster() {
        cout << "Hamster deleted" << endl;
    }
};

class BlueHamster: public Hamster {
public:
    void whoAmI() {
        cout << "I am a blue hamster" << endl;
    }
    
    ~BlueHamster() {
        cout << "BlueHamster deleted" << endl;
    }
};

class Aircraft {
protected:
    string name;
public:
    virtual void getMessage(string message, string towerName) = 0;
};

class Plane: public Aircraft {
public:
    Plane(string name) {
        this->name = name;
    }
    virtual void getMessage(string message, string towerName) {
        cout << "Plane " << name << " got a message from tower " << towerName << " :\n";
        cout << message << endl;
    }
};

class Helicopter: public Aircraft {
public:
    Helicopter(string name) {
        this->name = name;
    }
    virtual void getMessage(string message, string towerName) {
        cout << "Helicopter " << name << " got a message from tower " << towerName << " :\n";
        cout << message << endl;
    }
};

class Drone: public Aircraft {
public:
    Drone(string name) {
        this->name = name;
    }
    virtual void getMessage(string message, string towerName) {
        cout << "Drone " << name << " got a message from tower " << towerName << " :\n";
        cout << message << endl;
    }
};

class Tower {
    vector<Aircraft*> aircrafts;
    string name;
public:
    Tower(string name) {
        this->name = name;
    }
    void addAircraft(Aircraft& aircraft) {
        aircrafts.push_back(&aircraft);
    }
    
    void sendMessage(string message) {
        if(aircrafts.size() == 0)
            cout << "No aircrafts in the air" << endl;
        else {
            for (int i = 0; i < aircrafts.size(); i++) {
                aircrafts[i]->getMessage(message, name);
            }
        }
    }
};

class A {
public:
    virtual void foo() {
        cout << "foo(void) in A" << endl;
    }
    virtual void foo(int a) {
        cout << "foo(int) in A" << endl;
    }
    virtual void foo(float a) {
        cout << "foo(float) in A" << endl;
    }
};

class B: public A {
public:
    void foo() {
        cout << "foo(void) in B" << endl;
    }
//    void foo(int a) {
//        cout << "foo(int) in B" << endl;
//    }
//    void foo(float a) {
//        cout << "foo(float) in B" << endl;
//    }
};

int main(int argc, const char * argv[]) {
//    A* b = new B;
//    float a = 2.5;
//    b->foo();
//    b->foo(2);
//    b->foo(a);
//    delete b;
    
//==================ZADANIE 1=================================
    
    Circle circle;
    Square square;
    Triangle triangle;

    circle.draw();
    square.draw();
    triangle.draw();
    
    cout << "===================================================" << endl;
    
//==================ZADANIE 2=================================
    
    Rodent* rodents[3];
    Mouse m;
    rodents[0] = &m;
    Gerbil g;
    rodents[1] = &g;
    Hamster h;
    rodents[2] = &h;

    for(int i = 0; i < 3; i++)
        rodents[i]->whoAmI();
    
    cout << "===================================================" << endl;

    vector<Rodent*> rodentsVector;
    Mouse m2;
    Gerbil g2;
    Hamster h2;
    BlueHamster bh2;

    rodentsVector.push_back(&m2);
    rodentsVector.push_back(&g2);
    rodentsVector.push_back(&h2);
    rodentsVector.push_back(&bh2);


    for(int i = 0; i < rodentsVector.size(); i++)
        rodentsVector[i]->whoAmI();
    
    cout << "===================================================" << endl;
    
//==================ZADANIE 3=================================
    
    Tower tower("tower1");

    Helicopter h1("h1");
    Plane p1("p1");
    Drone d1("d1");

    tower.addAircraft(h1);
    tower.addAircraft(p1);
    tower.addAircraft(d1);

    tower.sendMessage("The weather is so nice today\n");

    return 0;
}
