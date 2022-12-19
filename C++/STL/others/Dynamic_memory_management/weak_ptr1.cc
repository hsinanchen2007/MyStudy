/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Person {
  public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;

    // Note, here is the major difference that makes shared_ptr/weak_ptr
    // 1. When objects are shared in a cycle, use weak_ptr will not internally increase counter
    //    but shared_ptr will, so at the end the Person is not destroryed with shared_ptr
    // 2. To access element in weak_ptr, we need additional lock() in the middle
    vector<weak_ptr<Person>> kids;   // weak pointer
    // vector<shared_ptr<Person>> kids;    // shared pointer

    Person (const string& n,
            shared_ptr<Person> m = nullptr,
            shared_ptr<Person> f = nullptr)
     : name(n), mother(m), father(f) {
    }

    ~Person() {
      cout << "delete " << name << endl;
    }
};

shared_ptr<Person> initFamily (const string& name)
{
    shared_ptr<Person> mom(new Person(name+"'s mom")); 
    shared_ptr<Person> dad(new Person(name+"'s dad")); 
    shared_ptr<Person> kid(new Person(name,mom,dad)); 
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

int main()
{
    shared_ptr<Person> p = initFamily("nico");

    cout << "nico's family exists" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    cout << "- name of 1st kid of nico's mom: " 
         << p->mother->kids[0].lock()->name << endl; // weak pointer, need to add "lock()" in the middle to access element
         // << p->mother->kids[0]->name << endl;     // shared pointer

    p = initFamily("jim");
    cout << "jim's family exists" << endl;
}

// output of weak pointer
// nico's family exists
// - nico is shared 1 times
// - name of 1st kid of nico's mom: nico
// delete nico
// delete nico's dad
// delete nico's mom
// jim's family exists
// delete jim
// delete jim's dad
// delete jim's mom

// output of shared pointer
// nico's family exists
// - nico is shared 3 times
// - name of 1st kid of nico's mom: nico
// jim's family exists
