/*
    From https://thispointer.com//when-should-i-use-virtual-functions-in-c/

    When to use virtual functions in C++?
    1 Comment / C++, C++ Interview Questions, virtual function / By Varun
    Best Courses to Learn C++11
    When we want a Derived Class to override a member function of Base class, then we should make that 
    member function in Base class virtual. So that if someone uses the Derived class object using Base 
    class’s pointer or reference to call the overridden member function, then function of derived class 
    should be called.

    Suppose draw() is a virtual member function in Base class i.e. Shape and in the Derived class i.e 
    Line this draw() function is overridden.

    [showads ad=inside_post]
    We assign the Line’s object in to Shape’s pointer and then calls the draw() member function from it. 
    Like this,

    Shape * ptr = new Line();
    ptr->draw(); // Line's Draw function will be called
    Advertisements



    As we have declared the draw() function as virtual in Base class hence ptr->draw() will call the Derived 
    class i.e. Line’s draw() function.

    But if draw() function is not virtual then same ptr->draw() will call the Base class i.e. Shape’s draw 
    function().

    By making it virtual we signals the compiler that don’t do the linking of this function call with actual 
    function address at compile time i.e. leave it for run time. At run time just check what’s the actual object 
    inside pointer or reference and call the correct virtual member function.

    But how does that help? Why someone will do that?

    Lets look in into an another case,

    Suppose we have a base class MessageCoverter that provides a member function, which coverts the passed message 
    into a specific format. In our application we use this class object to convert messages to required format.

    Message Converter Class,

    class MessageCoverter
    {
    public:
        std::string convert(std::string msg)
        {
            msg = "[START]" + msg + "[END]";
            return msg;
        }
    };
    MessageSender Class that uses this MessageConverter class,

    class MessageSender
    {
        MessageCoverter * mMsgCoverterPtr;
    public:
        MessageSender() :mMsgCoverterPtr(NULL){}
        void sendMessage(std::string msg)
        {
            if(mMsgCoverterPtr)
                msg = mMsgCoverterPtr->convert(msg);
            std::cout<<"Message Sent :: "<<msg<<std::endl;
        }
        void setMsgCoverterPtr(MessageCoverter * msgCoverterPtr) {
            mMsgCoverterPtr = msgCoverterPtr;
        }
    };
    In assigned the object of MessageConverter to MessageSender for converting messages before sending i.e.

        MessageSender msgSenderObj;
        MessageCoverter * msgConverterPtr = new MessageCoverter();
        msgSenderObj.setMsgCoverterPtr(msgConverterPtr);
        msgSenderObj.sendMessage("Hello World");
        delete msgConverterPtr;
    OUTPUT:
    Message Sent :: [START]Hello World[END]

    Till now every things work fine. Now suppose a new requirement comes, i.e. I need to convert the message in an 
    another format in some scenarios and I am not allowed to change either MessageConverter or MessageSender class.
    In this we will create a another class that will extend the MessageConverter class and will override the convert 
    member function with new one i.e.

    class NewMessageCoverter : public MessageCoverter
    {
    public:
        std::string convert(std::string msg)
        {
            msg = "<START> " + msg + " <END>";
            return msg;
        }
    };
    Now we will use this NewMessageConverter class with MessageSender class to convert the messages like this,

    MessageCoverter * newMsgConverterPtr = new NewMessageCoverter();
    msgSenderObj.setMsgCoverterPtr(newMsgConverterPtr);
    msgSenderObj.sendMessage("Hello World");
    delete newMsgConverterPtr;
    But wait a minute, lets look at the output first,

    OUTPUT:
    Message Sent :: [START]Hello World[END]

    It’s still showing the message in old format, it means new message conversion logic is not being used i.e. 
    NewMessageConvertter class’s convert message is not called instead it’s Base class i.e. MessageConverter’s 
    convert() member function is called.
    That happened because MessageSender calls convert() function using MemberConverter pointer and convert() 
    function was not declared virtual in the Base class i.e. MessageConverter.
    Therefore, compiler linked this convert() function call with with MessageConverter’s convert() function 
    while linking. It will not wait for run time linking.

    How to make MessageSender call actual Derived class i.e. NewMessageConverter’s member function convert() 
    instead of base class’s function?

    Make convert() function virtual in Base class i.e. MessageSender class i.e.

    class MessageCoverter
    {
    public:
        virtual std::string convert(std::string msg)
    };
    Output will now be,

    Message Sent :: <START> Hello World <END>

    So, conclusion is,

    If you have Derived class object in Base class’s pointer or reference and you want to call the Derived class’s 
    overridden member function from it then make that member function virtual in base class.
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

// message converter 1, base class
class MessageCoverter
{
public:
    MessageCoverter() { std::cout << "message converter 1" << std::endl; };
    // new code that use virtual function at base class, where it doesn't really
    // have the code of std::string convert(), so once it is called, it will determine
    // the corresonding real function
    // without below "virtual" keyword added, the code will execute converter 1 twice
    virtual std::string convert(std::string msg)
    { 
        msg = "<START1> " + msg + " <END1>";
        return msg;
    };
};

// message converter 2, derived class
// the class className : public anotherClassName defines the 
// current class can access another class
class NewMessageCoverter : public MessageCoverter
{
public:
    NewMessageCoverter() { std::cout << "message converter 2" << std::endl; };
    std::string convert(std::string msg)
    {
        msg = "<START2> " + msg + " <END2>";
        return msg;
    }
};

// API to call message converter
class MessageSender
{
    MessageCoverter * mMsgCoverterPtr;
public:
    MessageSender() : mMsgCoverterPtr(NULL){};
    void sendMessage(std::string msg)
    {
        if(mMsgCoverterPtr)
            msg = mMsgCoverterPtr->convert(msg);
        std::cout<<"Message Sent :: "<<msg<<std::endl;
    }
    void setMsgCoverterPtr(MessageCoverter * msgCoverterPtr) {
        mMsgCoverterPtr = msgCoverterPtr;
    }
};

int main()
{
    // call 1, from base class
    MessageSender msgSenderObj;
    MessageCoverter * msgConverterPtr = new MessageCoverter();
    msgSenderObj.setMsgCoverterPtr(msgConverterPtr);
    msgSenderObj.sendMessage("Hello World");
    delete msgConverterPtr;

    // call 2, from derived class, note that we create "NewMessageCoverter" 
    // as "MessageCoverter", as a derived class, at run time, program will
    // determine whether the object is calling base or derived class, based 
    // on what it's created and called
    MessageCoverter * newMsgConverterPtr = new NewMessageCoverter();
    msgSenderObj.setMsgCoverterPtr(newMsgConverterPtr);
    msgSenderObj.sendMessage("Hello World");
    delete newMsgConverterPtr;

    return 0;
}

// message converter 1
// Message Sent :: <START1> Hello World <END1>
// message converter 1
// message converter 2
// Message Sent :: <START2> Hello World <END2>
