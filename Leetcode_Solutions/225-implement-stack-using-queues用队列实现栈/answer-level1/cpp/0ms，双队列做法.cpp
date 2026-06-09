### 解题思路

![image.png](https://pic.leetcode-cn.com/4d4f72b29319091e3d6cd864eafb7ff82cc585974fe64d70dfbd8547cc384455-image.png)
使用两个队列q，a_q，其中a_q进行辅助操作。
push 直接push进q中
pop和top都需要把q中所有元素放进a_q队列中

### 代码

```cpp
class MyStack {
private:
    queue<int> q;
    queue<int> a_q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = -1;
        while(!q.empty()) {
            res = q.front(); q.pop();
            if(!q.empty()) a_q.push(res);
        }
        q.swap(a_q);
        return res;
        
    }
    
    /** Get the top element. */
    int top() {
        int res = -1;
        while(!q.empty()) {
            res = q.front(); q.pop();
            a_q.push(res);
        }
        q.swap(a_q);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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