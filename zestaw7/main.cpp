#include <iostream>
#include <vector>

using namespace std;

class Shape {
protected:
    virtual void draw() = 0;
};

class Circle: public Shape {
public:
    virtual void draw() {
        cout << "It is a circle" << endl;
    }
};

class Square: public Shape {
public:
    virtual void draw() {
        cout << "It is a square" << endl;
    }
};

class Triangle: public Shape {
public:
    virtual void draw() {
        cout << "It is a triangle" << endl;
    }
};

class Rodent {
public:
    virtual void whoAmI() // = 0; //zeby klasa byla czysto abstrakcyjna
    {
        cout << "Unknown type of rodent" << endl;
    }
};

class Mouse: public Rodent {
public:
    virtual void whoAmI() {
        cout << "I am a mouse" << endl;
    }
};

class Gerbil: public Rodent {
public:
    virtual void whoAmI() {
        cout << "I am a gerbil" << endl;
    }
};

class Hamster: public Rodent {
public:
    virtual void whoAmI() {
        cout << "I am a hamster" << endl;
    }
};

class BlueHamster: public Hamster {
public:
    virtual void whoAmI() {
        cout << "I am a blue hamster" << endl;
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


int main(int argc, const char * argv[]) {
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
    
    rodentsVector.push_back(&m2);
    rodentsVector.push_back(&g2);
    rodentsVector.push_back(&h2);
    
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
