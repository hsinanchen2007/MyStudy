### 解题思路
可以用O(n)的时间复杂度实现压入或者弹出
可以用两个队列实现
是在push的时候调整成类似于栈的输出顺序还是在输出的时候调整成栈的顺序

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        // 队列先入先出，栈先入后出
        // 多次出对入队
        // O(n)入栈
        // 双队列
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i=1; i<que.size(); ++i){
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = que.front();
        que.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    } 
private:
    queue<int> que; //单队列 
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


```