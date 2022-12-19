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

int main()
{
    // two shared pointers representing two persons by their name
    // Note: 
    // 1. Cannot do "shared_ptr<string> pNico = new string("nico");", it will be alwasy better to use "std::make_shared<string>("nico");"
    // 2. If we define shared_ptr without any assigned context, we need to use "pNico.reset(new string("nico"));"
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));

    // no assigned context, and later use make_shared<string>("myTest") to create it
    // by doing this way, no need to call reset
    shared_ptr<string> myTest;
    myTest = make_shared<string>("myTest1");

    // But if we need to use reset(), then we cannot use make_shared<string>("myTest2") way
    myTest.reset(new string("myTest2"));

    // capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");
    
    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    // print all elements
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;

    // overwrite a name again
    *pNico = "Nicolai";

    // print all elements again
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;
    
    // print some internal data
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}

// Jutta  Jutta  Nico  Jutta  Nico  
// Jutta  Jutta  Nicolai  Jutta  Nicolai  
// use_count: 4
