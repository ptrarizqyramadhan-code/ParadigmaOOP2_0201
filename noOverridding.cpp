#include <iostream>
using namespace std;

class baseClass final {
public:
    virtual void perkenalan() {
        cout << "halo saya function dari baseClass";
    }
};
class baseClass1 {
public:
    virtual void perkenalan() {
        cout << "halo saya function dari base Class";
    }
};
class darivedClass : public baseClass1 {
public:
    virtual void perkenalan() {
        cout << "halo saya function dari derived Class";
    }
};
int main()
{
    darivedClass a;
    a.perkenalan();

    return 0;
}