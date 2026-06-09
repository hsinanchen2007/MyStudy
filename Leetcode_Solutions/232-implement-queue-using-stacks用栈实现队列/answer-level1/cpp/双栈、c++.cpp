### 解题思路
![image.png](https://pic.leetcode-cn.com/38e40ef311c2fae9ec8cbc968d30169896d9fe43ebb61e30fb604ed70cb16bac-image.png)
利用两个栈将栈内的数据反转排列。

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!ans.empty())  //将第一个栈内的数据放到第二个栈中
        {
            anss.push(ans.top());
            ans.pop();
        }
        ans.push(x);  //将新元素进栈，即放在栈的尾部
        while(!anss.empty())  //将另一个栈中的元素放回原栈
        {
            ans.push(anss.top());
            anss.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int front = ans.top();
        ans.pop();
        return front;
    }
    
    /** Get the front element. */
    int peek() {
        return ans.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return ans.empty();
    }
    private:
    stack<int> ans;
    stack<int> anss;
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