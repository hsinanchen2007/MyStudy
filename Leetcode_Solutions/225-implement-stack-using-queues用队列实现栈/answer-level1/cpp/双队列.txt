### 解题思路
双队列，push操作时间复杂度O(1),pop操作为O(n)

### 代码

```cpp
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int topvalue;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topvalue=x;//保存栈顶元素
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q1.size()>1){
            topvalue=q1.front();//保存最后一次弹出的元素，即下一次操作时的栈顶元素
            q2.push(topvalue);
            q1.pop();
        }
        int ans=q1.front();
        q1.pop();

        swap(q1,q2);
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return topvalue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty()&&q2.empty()) return true;
        else return false;
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