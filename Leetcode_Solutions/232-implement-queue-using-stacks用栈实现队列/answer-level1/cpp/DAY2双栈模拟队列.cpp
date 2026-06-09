### 解题思路
在做完上一道类似的两个队列模拟栈，我找到了这道两个栈模拟队列的题。
注释掉的部分是以前做的有问题不到位的地方。
感谢题解里的一位答主写的题解，帮助我解决了问题。

### 代码

```cpp
class MyQueue {
public:
    /*定a为输入栈，b为输出栈*/
    stack<int> a,b;
    /** Initialize your data structure here. */
    MyQueue() {
 
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        /*
        if(b.empty()){
            b.push(a.peek());
        }
       return b.top;*/

       if(b.empty()){
            while(a.size()) {
                b.push(a.top());
                a.pop();
            }
        }
        int x=b.top();
        b.pop();
        return x;


    }
    
    /** Get the front element. */
    int peek() {
      /* if(b.empty())
       {
            b.push(a.top());
       }
       return b.top;
       */
       if(b.empty()){
            while(a.size()) {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(a.empty()&&b.empty())
            return true;
        else
            return false;
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