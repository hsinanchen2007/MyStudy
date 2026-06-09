### 解题思路
这里我们有了peek的操作，和之前的有道题又不太一致。
这里，我们需要做的是保持主栈的顺序不变，只是输出的数据需要维持队的性质。
所以，在使用副栈进行过度，得到想要的数据后，还要变回到主栈中；
这样，后面再进行push操作的话，就不会改变原有的结构了。


### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        main_stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(main_stk.empty() && help_stk.empty()) return -1;
        if(!main_stk.empty()){
            while(!main_stk.empty()){
                help_stk.push(main_stk.top());
                main_stk.pop();
            }
        }
        int a = help_stk.top();
        help_stk.pop();
        while(!help_stk.empty()){
            main_stk.push(help_stk.top());
            help_stk.pop();
        }
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        if(main_stk.empty() && help_stk.empty()) return -1;
        if(!main_stk.empty()){
            while(!main_stk.empty()){
                help_stk.push(main_stk.top());
                main_stk.pop();
            }
        }
        int a = help_stk.top();
        while(!help_stk.empty()){
            main_stk.push(help_stk.top());
            help_stk.pop();
        }
        return a;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(main_stk.empty()) return true;
        else return false;
    }
private:
    stack<int> main_stk;
    stack<int> help_stk;
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