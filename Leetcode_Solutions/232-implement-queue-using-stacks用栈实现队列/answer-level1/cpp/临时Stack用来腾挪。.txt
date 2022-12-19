### 解题思路
![image.png](https://pic.leetcode-cn.com/bb43bcea0b66a292ca4bfe136d31f9c111a07bd821b28c1131785faff378b442-image.png)

此处撰写解题思路

### 代码

```cpp

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        data = {};
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> temp={};
        while(!data.empty()){
            temp.push(data.top());
            data.pop();
        }
        int res = temp.top();
        temp.pop();
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> temp={};
        while(!data.empty()){
            temp.push(data.top());
            data.pop();
        }
        int res = temp.top();
        while (!temp.empty()) {
            data.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
    stack<int> data;
};
```