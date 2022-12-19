

### 代码

```cpp
#include <stack>

//双栈法
//法1： 每次入栈都让队尾元素在栈底

class MyQueue {
public:
    stack<int> orgStk;
    stack<int> subStk;
    int front;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(orgStk.empty()){
            front = x;
        }
        while(!orgStk.empty()){
            int tmp = orgStk.top();
            orgStk.pop();
            subStk.push(tmp);
        }
        orgStk.push(x);
        while(!subStk.empty()){
            int tmp = subStk.top();
            subStk.pop();
            orgStk.push(tmp);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!orgStk.empty()){
            int res = orgStk.top();
            orgStk.pop();
            return res;
        }
        return -233;
    }
    
    /** Get the front element. */
    int peek() {
        if(!orgStk.empty()){
            return orgStk.top();
        }
        return -233;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return orgStk.empty();
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

第二种方法，官方题解里用到了摊还分析
```cpp
#include <stack>

//双栈法
//法2：区分input stack与output stack
//     当需要pop，且output stack为空时再弹栈

class MyQueue {
public:
    stack<int> inputStk;
    stack<int> outputStk;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inputStk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //未考虑两个stack都为空的情况
        if(outputStk.empty()){
            while(!inputStk.empty()){
                int tmp = inputStk.top();
                inputStk.pop();
                outputStk.push(tmp);
            }
        }

        int res = outputStk.top();
        outputStk.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        //未考虑两个stack都为空的情况
        if(outputStk.empty()){
            while(!inputStk.empty()){
                int tmp = inputStk.top();
                inputStk.pop();
                outputStk.push(tmp);
            }
        }

        int res = outputStk.top();
        //outputStk.pop();
        return res;  
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inputStk.empty() && outputStk.empty();
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