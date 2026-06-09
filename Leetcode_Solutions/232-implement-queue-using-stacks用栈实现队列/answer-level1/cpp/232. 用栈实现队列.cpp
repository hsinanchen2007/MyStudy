核心思路，建立2个栈，s1,s2，定义移动栈的函数movestack(s1,s2)
push时，movestack(s2,s1) s1.push(x);
pop时，move(s1,s2) s2.pop();
top时 move(s1,s2) return s2.top()
empty则判断s1.empty() && s2.empty()
```
#include<stack>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        moveStack(s2, s1);
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        moveStack(s1, s2);
        int x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        moveStack(s1, s2);
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    static void moveStack(stack<int>& s1, stack<int>& s2)
    {
        while (!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
    }
    stack<int> s1;
    stack<int> s2;
};

```
