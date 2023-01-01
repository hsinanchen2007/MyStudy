/*
    From https://thispointer.com//designing-callbacks-in-c-part-1-function-pointers/

    Designing Callbacks in C++ – Part 1: Function Pointers
    5 Comments / C++, C++ Interview Questions, Callbacks, Function Pointers / By Varun
    Best Courses to Learn C++11
    In this article we will discuss what is a callback and what types of callbacks we can 
    have in C++ and how to Design Callbacks as function pointers.

    Now what is a callback?

    Callback is a function that we pass to another APIs as argument while calling them. 
    Now these APIs are expected to use our provided callback at some point.

    Callbacks in C++ can be of 3 types,

    Advertisements



    1.) Function Pointer
    2.) Function Objects / Functors
    3.) Lambda functions

    Behaviour or result of the API is dependent on the callback we provide i.e. if we keep 
    the input to API same and just change the callback then the output of API will change. 
    Let’s understand this by,

    Using Function Pointer as callback:

    From a framework we got an API that can build complete message from provided raw data. 
    This API will perform following steps,

    1.) Add header and footer in raw Data to make the message.
    2.) Encrypt the complete message.
    3.) Return the message

    Now this API knows what header and footer to apply but don’t know about exact encryption 
    logic, because that is not fixed to Framework, that can change from application to application. 
    As, Encryption Logic is application dependent, therefore in this API provides a provision 
    to pass encryption logic as a callback function pointer. This API will call back the code 
    of application by calling this passed function pointer.

    Callback Mechanism Exmplained
    Callback Mechanism
    Framework’s API that accepts the function pointer callback as an argument is as follows,

    std::string buildCompleteMessage(std::string rawData, std::string (* encrypterFunPtr)(std::string) )
    {
        // Add some header and footer to data to make it complete message
        rawData = "[HEADER]" + rawData + "[FooTER]";
        // Call the callBack provided i.e. function pointer to encrypt the
        rawData = encrypterFunPtr(rawData);
        return rawData;
    }
    Now when an application calls this API of framework to build the message, it passes a pointer 
    to its local function as an argument.

    [showads ad=inside_post]
    In this case this a function Pointer is a Callback,

    //This encrypt function increment all letters in string by 1.
    std::string encryptDataByLetterInc(std::string data)
    {
        for(int i = 0; i < data.size(); i++)
        {
            if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
                data[i]++;
        }
        return data;
    }
    This encrypt function increment all letters in string by 1.

    Now lets call build message API will this function as callback,

    std::string msg = buildCompleteMessage("SampleString", &encryptDataByLetterInc);
        std::cout<<msg<<std::endl;
    Output:

    [IFBEFS]TbnqmfTusjoh[GppUFS]

    Now, lets design a new type of encryption function,

    //This encrypt function decrement all letters in string by 1.
    std::string encryptDataByLetterDec(std::string data)
    {
        for(int i = 0; i < data.size(); i++)
        {
            if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
                data[i]--;
        }
        return data;
    }
    This encrypt function decrement all letters in string by 1. Now lets call build message 
    API will this function as callback,

    std::string msg = buildCompleteMessage("SampleString", &encryptDataByLetterDec);
    std::cout<<msg<<std::endl;
    Output:

    [GD@CDQ]R`lokdRsqhmf[EnnSDQ]

    Now output of this call  is different to earlier.
    We kept the API and passed data same but changed the passed callback, as a result behaviour 
    or result of API changed.

    This shows, that behaviour or result of the API is dependent on the callback passed as an argument.

    Till now we have seen how to use function pointer as a callback. But,

    What is a Function Object Callback?
    Why do we need function objects?

    We will discuss this in next article.
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

//This encrypt function increment all letters in string by 1.
std::string encryptDataByLetterInc(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]++;
    }
    return data;
}

//This encrypt function decrement all letters in string by 1.
std::string encryptDataByLetterDec(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]--;
    }
    return data;
}

std::string buildCompleteMessage(std::string rawData, std::string (* encrypterFunPtr)(std::string) )
{
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";

    // Call the callBack provided i.e. function pointer to encrypt the
    // The "encrypterFunPtr" is the name defined as function's pointer, which can be called 
    // by different callback functions, depends on the given input argument of this function
    rawData = encrypterFunPtr(rawData);

    return rawData;
}

// main
int main() {
    std::string msg1 = buildCompleteMessage("SampleString", &encryptDataByLetterInc);
    std::cout << msg1 << std::endl;
    std::string msg11 = buildCompleteMessage(msg1, &encryptDataByLetterDec);
    std::cout << msg11 << std::endl;

    std::string msg2 = buildCompleteMessage("SampleString", &encryptDataByLetterDec);
    std::cout << msg2 << std::endl;
    std::string msg22 = buildCompleteMessage(msg2, &encryptDataByLetterInc);
    std::cout << msg22 << std::endl;

    return 0;
}

// [IFBEFS]TbnqmfTusjoh[GppUFS]
// [GD@CDQ][HEADER]SampleString[FooTER][EnnSDQ]
// [GD@CDQ]R`lokdRsqhmf[EnnSDQ]
// [IFBEFS][HE@DER]S`mpleString[FooTER][GppUFS]

