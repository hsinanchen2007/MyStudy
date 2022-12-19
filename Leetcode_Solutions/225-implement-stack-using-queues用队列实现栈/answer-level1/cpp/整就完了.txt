### 解题思路
此处撰写解题思路

1、两个队列，栈push元素的时候，直接que1存元素；
2、栈pop元素的，把que1里的非最后一个元素全都放到que2里，最后que1只剩下了一个元素，直接把que1的元素pop出来
3、别忘了que1最后pop以后，把que2的元素再折腾回que1
4、两个栈实现队列那个题，不用折腾回去

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        int a;
        int size = que1.size();
        if (size > 1)
        {
            
            while(size - 1 != 0)
            {
                size--;
                a = que1.front();
                que1.pop();
                que2.push(a);
            }
        }
        a = que1.front();
        que1.pop();
        while(!que2.empty())
        {
            int num = que2.front();
            que2.pop();
            que1.push(num);
        }
        return a;
    }
    
    /** Get the top element. */
    int top() {
        int a;
        int size = que1.size();
        if (size > 1)
        {
            
            while(size - 1 != 0)
            {
                size--;
                a = que1.front();
                que1.pop();
                que2.push(a);
            }
        }
        a = que1.front();
        que1.pop();
        que2.push(a);
        while(!que2.empty())
        {
            int num = que2.front();
            que2.pop();
            que1.push(num);
        }
        return a;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (que1.empty() && que2.empty())
        {
            return true;
        }
        return false;
    }
    queue<int> que1;
    queue<int> que2;
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