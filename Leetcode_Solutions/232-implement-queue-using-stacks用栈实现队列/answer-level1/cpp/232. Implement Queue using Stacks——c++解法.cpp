### 解题思路
1. 首先要对我们的核心方法写一个函数，核心方法是**建立2个栈，pushStk和popStk**，然后将**pushStk中的元素一股脑地push进popStk中。pushStk2popStk前是pushStk满、popStk空；pushStk2popStk后是pushStk空，popStk满。
2. 要明白，题目给的函数中，push()函数和empty()函数是可以在pushStk2popStk()工作前调用的。
3. pop()和peek()函数，都要在popStk中已经装满了元素的前提下，才能调用他们俩。
4. 此番的错误点，在pushStk2popStk()函数中，栈2取栈1元素的时候，直接是S2.push(S1.pop())。
```c++
popStk.push(pushStk.pop());
```
这样是错误的。正确是先取top()，再pop()。下面这样——
```c++
popStk.push(pushStk.top());
pushStk.pop();
```
5. 第2个错误点就是在peek函数中，没有先调用pushStk2popStk()函数。应该先调用的，原因上面说过了。
```c++
/** Get the front element. */
    int peek() 
    {
        pushStk2popStk();  // peek函数的前提，也是要popStk中有元素了才能操作

        int res = popStk.top();
        return res;
    }
```

### 代码

```cpp
class MyQueue 
{

private:
    stack<int> pushStk;
    stack<int> popStk;

public:

    void pushStk2popStk()
    {
        if (popStk.empty())
        {
            while(!pushStk.empty())
            {
                // popStk.push(pushStk.pop()); // 不能在往栈1中push元素的时候，直接从栈2中pop()一个元素出来
                popStk.push(pushStk.top());
                pushStk.pop();
            }
        }
    }
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        pushStk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        // 先保证popStk中是有元素的
        pushStk2popStk();

        int res;
        // 现在只要将popStk中的元素都弹出来就好了

        res = popStk.top();
        popStk.pop();        // 这里忘记取完栈顶元素后，再pop()出去

        return res;


    }
    
    /** Get the front element. */
    int peek() 
    {
        pushStk2popStk();  // peek函数的前提，也是要popStk中有元素了才能操作

        int res = popStk.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return pushStk.empty() && popStk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```