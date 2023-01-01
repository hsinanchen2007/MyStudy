/*
    From https://thispointer.com//designing-callbacks-in-c-part-2-function-objects-functors/

    Designing Callbacks in C++ – Part 2: Function Objects & Functors
    1 Comment / C++, C++ Interview Questions, Function Objects, Function Pointers, 
    Functor / By Varun
    
    Best Courses to Learn C++11
    In this article we will discuss, what is a Function Object, why do we need function objects 
    and how to use function objects as Callbacks.

    What is a Function Objects:

    A Function Object / Functor is a kind of Callback with State.

    In a Programmer’s terminology,

    Object of a class which has overloaded operator() is called Function Object or Functor i.e. 
    a class with overloaded operator() function is as follows,

    #include <iostream>
    class MyFunctor
    {
    public:
        int operator()(int a , int b)
        {
            return a+b;
        }
    };
    Now lets create a function object and call them,

    MyFunctor funObj;
    std::cout<<funObj(2,3)<<std::endl;
    Function objects / Functors can be called just like normal functions i.e.

    MyFunctor funObj;
    funObj(2,3);
    is similar to following code,

    MyFunctor funObj;
    funObj.operator ()(2,3);
    Let’s understand by a practice example,

    In previous article we discussed how to use function pointer call back to change the behaviour 
    of message builder API. Checkout the article here,

    Designing Callbacks with Function Pointers in C++

    Let’s refresh the problem statement,

    From a framework we got an API that can build complete message from provided raw data. 
    This API will perform following steps,

    1.) Add header and footer in raw Data to make the message.
    2.) Encrypt the complete message.
    3.) Return the message

    [showads ad=inside_post]

    Now this API knows what header and footer to apply but don’t know about exact encryption logic, 
    because that is not fixed to Framework, that can change from application to application.
    As, Encryption Logic is application dependent, therefore it provides a provision to pass encryption 
    logic as a callback function pointer,

    std::string buildCompleteMessage(std::string rawData,
            std::string (*encrypterFunPtr)(std::string)) {
        // Add some header and footer to data to make it complete message
        rawData = "[HEADER]" + rawData + "[FooTER]";
        // Call the callBack provided i.e. function pointer to encrypt the
        rawData = encrypterFunPtr(rawData);
        return rawData;
    }
    No suppose in our application we want to call this framework API three times with 3 different types 
    of encryption logics i.e.

    Encrypt by incrementing each letter by 1.
    Encrypt by incrementing each letter by 2.
    Encrypt by decrementing each letter by 1.

    How to this through function pointers,

    For this we need to create three different types of functions and use them as function pointers 
    while calling this API.
    3 different functions here are necessary because normal global functions don’t have any state 
    associated with them,

    //This encrypt function increment all letters in string by 1.
    std::string encryptDataByLetterInc1(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
                data[i]++;
        return data;
    }
    //This encrypt function increment all letters in string by 2.
    std::string encryptDataByLetterInc2(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
                data[i] = data[i] + 2;
        return data;
    }
    //This encrypt function increment all letters in string by 1.
    std::string encryptDataByLetterDec(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
                data[i] = data[i] - 1;
        return data;
    }
    int main() {
        std::string msg = buildCompleteMessage("SampleString",
                &encryptDataByLetterInc1);
        std::cout << msg << std::endl;
        msg = buildCompleteMessage("SampleString", &encryptDataByLetterInc2);
        std::cout << msg << std::endl;
        msg = buildCompleteMessage("SampleString", &encryptDataByLetterDec);
        std::cout << msg << std::endl;
        return 0;
    }
    Is there any way to bind state with function pointers?

    Answers is yes –  By making the them function objects or functors.

    Let’s create a Function Object / Functor for Encryption:

    A function object or functor, is an object that has operator () defined as member function i.e.

    class Encryptor {
        bool m_isIncremental;
        int m_count;
    public:
        Encryptor() {
            m_isIncremental = 0;
            m_count = 1;
        }
        Encryptor(bool isInc, int count) {
            m_isIncremental = isInc;
            m_count = count;
        }
        std::string operator()(std::string data) {
            for (int i = 0; i < data.size(); i++)
                if ((data[i] >= 'a' && data[i] <= 'z')
                        || (data[i] >= 'A' && data[i] <= 'Z'))
                    if (m_isIncremental)
                        data[i] = data[i] + m_count;
                    else
                        data[i] = data[i] - m_count;
            return data;
        }
    };
    These function objects can be called just like functions in message builder API.

    std::string buildCompleteMessage(std::string rawData,
            Encryptor encyptorFuncObj) {
        // Add some header and footer to data to make it complete message
        rawData = "[HEADER]" + rawData + "[FooTER]";
        // Call the callBack provided i.e. function pointer to encrypt the
        rawData = encyptorFuncObj(rawData);
        return rawData;
    }
    What just happened here is a temporary object of EncruptFunctor is created and operator () is 
    called on it.

    It can also be called like,

    Encryptor(true, 1);
    It similar to calling,

    Encryptor tempObj;
    tempObj.operator(true, 1);
    Now use this function object two solve our problem. Create a function object that can encrypt 
    by decementing / increment each letter by specified number of times.

    int main() {
        std::string msg = buildCompleteMessage("SampleString", Encryptor(true, 1));
        std::cout << msg << std::endl;
        msg = buildCompleteMessage("SampleString", Encryptor(true, 2));
        std::cout << msg << std::endl;
        msg = buildCompleteMessage("SampleString", Encryptor(false, 1));
        std::cout << msg << std::endl;
        return 0;
    }
    So, this is how we can use function objects as callbacks.

    Complete executable code is as follows,
*/

// some often common headers and namespace
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class Encryptor {
    bool m_isIncremental;
    int m_count;

public:
    Encryptor() {
        m_isIncremental = 0;
        m_count = 1;
    }

    Encryptor(bool isInc, int count) {
        m_isIncremental = isInc;
        m_count = count;
    }

    std::string operator()(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
                if (m_isIncremental)
                    data[i] = data[i] + m_count;
                else
                    data[i] = data[i] - m_count;
        return data;
    }
};

std::string buildCompleteMessage(std::string rawData,Encryptor encyptorFuncObj) {
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";

    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encyptorFuncObj(rawData);

    return rawData;
}

int main() {
    std::string msg = buildCompleteMessage("SampleString", Encryptor(true, 1));
    std::cout << msg << std::endl;

    msg = buildCompleteMessage("SampleString", Encryptor(true, 2));
    std::cout << msg << std::endl;

    msg = buildCompleteMessage("SampleString", Encryptor(false, 1));
    std::cout << msg << std::endl;

    return 0;
}

// [IFBEFS]TbnqmfTusjoh[GppUFS]
// [JGCFGT]UcorngUvtkpi[HqqVGT]
// [GD@CDQ]R`lokdRsqhmf[EnnSDQ]
