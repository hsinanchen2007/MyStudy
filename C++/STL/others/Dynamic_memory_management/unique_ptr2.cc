/*
    From https://thispointer.com/c11-unique_ptr-tutorial-and-examples/

    C++11 Smart Pointer – Part 6 : unique_ptr<> Tutorial and Examples
    2 Comments / C++, C++ 11, Smart Pointers / By Varun
    Best Courses to Learn C++11
    In this article we will discuss a Smart Pointer implementationstd::unique_ptr<> provided by c++11.


    what is std::unique_ptr ?
    unique_ptr<> is one of the Smart pointer implementation provided by c++11 to prevent memory leaks. A unique_ptr object wraps around a raw pointer and its responsible for its lifetime. When this object is destructed then in its destructor it deletes the associated raw pointer.
    unique_ptr has its -> and * operator overloaded, so it can be used similar to normal pointer.

    Checkout the following example,
    #include <iostream>
    #include <memory>
    struct Task
    {
        int mId;
        Task(int id ) :mId(id)
        {
            std::cout<<"Task::Constructor"<<std::endl;
        }
        ~Task()
        {
            std::cout<<"Task::Destructor"<<std::endl;
        }
    };
    int main()
    {
        // Create a unique_ptr object through raw pointer
        std::unique_ptr<Task> taskPtr(new Task(23));
        //Access the element through unique_ptr
        int id = taskPtr->mId;
        std::cout<<id<<std::endl;
        return 0;
    }

    Output:
    Task::Constructor
    23
    Task::Destructor

    unique_ptr<Task> object taskPtr accepts a raw pointer as arguments. Now when function will exit, this object will go out of scope and its destructor will be called. In its destructor unique_ptr object taskPtr deletes the associated raw pointer.

    So, even if function is exited normally or abnormally (due to some exception), destructor of taskPtr will always be called. Hence, raw pointer will always get deleted and prevent the memory leak.

    Unique Ownership of unique pointer
    A unique_ptr object is always the unique owner of associated raw pointer. We can not copy a unique_ptr object, its only movable.

    As each unique_ptr object is sole owner of a raw pointer, therefore in its destructor it directly deletes the associated pointer. There is no need of any reference counting, therefore its very light.

    Creating a empty unique_ptr object
    Let’s create a empty unique_ptr<int> object i.e.
    // Empty unique_ptr object
    std::unique_ptr<int> ptr1;

    ptr1 has no raw pointer associated with it. Hence its empty.
    Check if a unique_ptr<> object is empty
    There are two ways to check if a unique_ptr<> object is empty or it has a raw pointer associated with it i.e.

    Method 1 :
    // Check if unique pointer object is empty
    if(!ptr1)
        std::cout<<"ptr1 is empty"<<std::endl;

    Method 2:
    // Check if unique pointer object is empty
    if(ptr1 == nullptr)
        std::cout<<"ptr1 is empty"<<std::endl;
    Creating a unique_ptr object with raw pointer
    To create a unique_ptr<> object that is non empty, we need to pass the raw pointer in its constructor while creating the object i.e.
    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr(new Task(23));

    We can not create a unique_ptr<> object through assignment, otherwise it will cause compile error
    // std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error
    Reseting a unique_ptr
    Calling reset() function on a unique_ptr<> object will reset it i.e. it will delete the associated raw pointer and make unique_ptr<> object empty i.e.
    // Reseting the unique_ptr will delete the associated
    // raw pointer and make unique_ptr object empty
    taskPtr.reset();
    unique_ptr object is not copyable
    As unique_ptr<> is not copyable, only movable. Hence we can not create copy of a unique_ptr object either through copy constructor or assignment operator.
    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr2(new Task(55));
    // Compile Error : unique_ptr object is Not copyable
    std::unique_ptr<Task> taskPtr3 = taskPtr2; // Compile error
    // Compile Error : unique_ptr object is Not copyable
    taskPtr = taskPtr2; //compile error

    Both copy constructor and assignment operator are deleted in unique_ptr<> class.
    Transfering the ownership of unique_ptr object
    We cannot copy a unique_ptr object, but we can move them. It means a unique_ptr object can transfer the owner ship of associated raw pointer to another unique_ptr object. Let’s understand by an example,

    Create a unique_ptr Object i.e.
    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr2(new Task(55));

    taskPtr2 is not empty.
    Now transfer the ownership of associated pointer of Task to a new unique_ptr object i.e.
    {
        // Transfer the ownership
        std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
        if(taskPtr2 == nullptr)
            std::cout<<"taskPtr2 is  empty"<<std::endl;
        // ownership of taskPtr2 is transfered to taskPtr4
        if(taskPtr4 != nullptr)
            std::cout<<"taskPtr4 is not empty"<<std::endl;
        std::cout<<taskPtr4->mId<<std::endl;
        //taskPtr4 goes out of scope and deletes the associated raw pointer
    }

    std::move() will convert the taskPtr2 to a RValue Reference. So that move constructor of unique_ptr is invoked and associated raw pointer can be transferred to taskPtr4.
    taskPtr2 will be empty after transferring the ownership of its raw pointer to taskPtr4.

    Releasing the associated raw pointer
    Calling release() on unique_ptr object will release the ownership of associated raw pointer from the object.
    It returns the raw pointer.
    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr5(new Task(55));
    if(taskPtr5 != nullptr)
        std::cout<<"taskPtr5 is not empty"<<std::endl;
    // Release the ownership of object from raw pointer
    Task * ptr = taskPtr5.release();
    if(taskPtr5 == nullptr)
        std::cout<<"taskPtr5 is empty"<<std::endl;

    Checkout complete example as follows
*/

#include <iostream>
#include <memory>
struct Task
{
    int mId;
    Task(int id ) :mId(id)
    {
        std::cout<<"Task::Constructor"<<std::endl;
    }
    ~Task()
    {
        std::cout<<"Task::Destructor"<<std::endl;
    }
};

int main()
{
    // Empty unique_ptr object
    std::unique_ptr<int> ptr1;

    // Check if unique pointer object is empty
    if(!ptr1)
        std::cout<<"ptr1 is empty"<<std::endl;

    // Check if unique pointer object is empty
    if(ptr1 == nullptr)
        std::cout<<"ptr1 is empty"<<std::endl;

    // can not create unique_ptr object by initializing through assignment
    // std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error
    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr(new Task(23));

    // Check if taskPtr is empty or it has an associated raw pointer
    if(taskPtr != nullptr)
        std::cout<<"taskPtr is  not empty"<<std::endl;

    //Access the element through unique_ptr
    std::cout<<taskPtr->mId<<std::endl;
    std::cout<<"Reset the taskPtr"<<std::endl;

    // Reseting the unique_ptr will delete the associated
    // raw pointer and make unique_ptr object empty
    taskPtr.reset();

    // Check if taskPtr is empty or it has an associated raw pointer
    if(taskPtr == nullptr)
        std::cout<<"taskPtr is  empty"<<std::endl;

    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr2(new Task(55));
    if(taskPtr2 != nullptr)
        std::cout<<"taskPtr2 is  not empty"<<std::endl;

    // unique_ptr object is Not copyable
    //taskPtr = taskPtr2; //compile error
    // unique_ptr object is Not copyable
    //std::unique_ptr<Task> taskPtr3 = taskPtr2;
    {
        // Transfer the ownership
        std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
        if(taskPtr2 == nullptr)
            std::cout<<"taskPtr2 is  empty"<<std::endl;
        // ownership of taskPtr2 is transfered to taskPtr4
        if(taskPtr4 != nullptr)
            std::cout<<"taskPtr4 is not empty"<<std::endl;
        std::cout<<taskPtr4->mId<<std::endl;
        //taskPtr4 goes out of scope and deletes the assocaited raw pointer
    }

    // Create a unique_ptr object through raw pointer
    std::unique_ptr<Task> taskPtr5(new Task(55));
    if(taskPtr5 != nullptr)
        std::cout<<"taskPtr5 is not empty"<<std::endl;

    // Release the ownership of object from raw pointer
    Task * ptr = taskPtr5.release();
    if(taskPtr5 == nullptr)
        std::cout<<"taskPtr5 is empty"<<std::endl;
    std::cout<<ptr->mId<<std::endl;

    delete ptr;

    return 0;
}

// ptr1 is empty
// ptr1 is empty
// Task::Constructor
// taskPtr is  not empty
// 23
// Reset the taskPtr
// Task::Destructor
// taskPtr is  empty
// Task::Constructor
// taskPtr2 is  not empty
// taskPtr2 is  empty
// taskPtr4 is not empty
// 55
// Task::Destructor
// Task::Constructor
// taskPtr5 is not empty
// taskPtr5 is empty
// 55
// Task::Destructor
