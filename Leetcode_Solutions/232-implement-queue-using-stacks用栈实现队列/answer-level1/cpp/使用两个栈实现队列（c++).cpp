思路：

使用两个栈：stk1, stk2
stk1 用来存放 `push`的元素
stk2 用来实现 `peek()` 和 `pop()`, 使用stk2时，当其为空时，将stk1的元素弹出转移过来，得到的顺序符合队列的排序

![Screenshot from 2019-07-25 14-51-03.png](https://pic.leetcode-cn.com/381858bdc738eccc5b3ab4d165c1144a0fe8ff1cdf7bf785136f2dedac1947ca-Screenshot%20from%202019-07-25%2014-51-03.png)

``` c
class MyQueue {
private:
    stack<int> stk1, stk2;  
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        res = peek();
        stk2.pop();
        return res;
        
    }
    
    /** Get the front element. */
    int peek() {
        int res;
        if( stk2.empty()) {
            assert( !stk1.empty());
            while( !stk1.empty()) {
                stk2.push( stk1.top());
                stk1.pop();
            }
        }
        res = stk2.top();
        return res;
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();    
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
