### 解题思路
法1.使用双队列模拟栈
    push插入时只插入其中一个非空队列；
    pop弹出时，借助另一个空队列，把size()-1个元素插入另一个空队列，弹出第size()个元素。

法2.使用单队列模拟栈
    每新插入一个元素，都把该元素之前的所有元素重新入队，使用保持新插入元素位于队头。

![image.png](https://pic.leetcode-cn.com/6f37dddbc7dbbfe4d45bf08c826ff8f7d2baa94fc0a8898dedc1e1ae88e5f54f-image.png)


### 代码

```cpp
class MyStack {
private:
    //使用双队列实现
    queue<int> q1;
    queue<int> q2;

    //使用单队列实现
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    //方法1：使用双队列实现栈
    /*
    // Push element x onto stack. 
    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }
    
    // Removes the element on top of the stack and returns that element. 
    int pop() {
        int res = -1;
        if(!q1.empty()){
            while(!q1.empty()){
                if(q1.size() != 1)
                    q2.push(q1.front());
                else
                    res = q1.front();
                
                q1.pop();
            }
        }
        else{
            while(!q2.empty()){
                if(q2.size() != 1)
                    q1.push(q2.front());
                else
                    res = q2.front();

                q2.pop();
            }
        }
        return res;
    }
    
    // Get the top element. 
    int top() {
        int res = -1;
        if(!q1.empty()){
            while(!q1.empty()){
                if(q1.size() == 1)
                    res = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
        }
        else{
            while(!q2.empty()){
                if(q2.size() == 1)
                    res = q2.front();
                q1.push(q2.front());
                q2.pop();
            }
        }
        return res;
    }
    
    // Returns whether the stack is empty. 
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
    */

    //方法2：使用单队列实现栈
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        //每新插入一个元素，都把该元素之前的所有元素重新入队，使用保持新插入元素位于队头
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = top();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
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