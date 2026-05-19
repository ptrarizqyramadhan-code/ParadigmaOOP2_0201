#include <iostream>
using namespace std;

class baseClass
{
public:
    virtual void perkenalan()
    {
        cout << "Hallo saya Function dari base class" << endl;
    }
};
class darivedClass : public baseClass
{
public:
    void perkenalan1()
    {
        cout << "Hallo saya Function dari darived class";
    }
