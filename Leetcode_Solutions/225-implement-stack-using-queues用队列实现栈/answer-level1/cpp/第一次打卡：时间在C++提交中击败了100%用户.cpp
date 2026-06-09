### 解题思路
将主要处理放在了在pop处，top()随着push和pop的进行及时更新，push每次都加入到非空的队列中。
pop时如果剩下的元素>=2个，就及时更新top，否则只有一个元素，不更新top
（题目假设不会出现对空栈不会进行top,pop操作，不然这样不更新top是危险的）

### 代码

```cpp
class MyStack {
private:
    queue<int> que1;
    queue<int> que2;
    int S_top;
public:
    /** Initialize your data structure here. */
    MyStack() {
        //queue<int> q1;
        //queue<int> q2;
        //int flag = 1;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(que1.empty()) {
            que2.push(x);
        }
        else if(que2.empty()) {
            que1.push(x);
        }
        S_top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans;
        if(que1.empty()) {
            while(que2.size() > 2) {
                que1.push(que2.front());
                que2.pop();
            }
            if(que2.size() == 2) {
                S_top = que2.front();
                que1.push(S_top);
                que2.pop();
            }
            ans = que2.front();
            que2.pop();
        }
        else {
            while(que1.size() > 2) {
                que2.push(que1.front());
                que1.pop();
            }
            if(que1.size() == 2) {
                S_top = que1.front();
                que2.push(S_top);
                que1.pop();
            }
            ans = que1.front();
            que1.pop();
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return S_top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(que1.empty() && que2.empty()) {
            return true;
        }
        return false;
    }
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