### 解题思路
此处撰写解题思路
1、想象一个装羽毛球的那个圆筒；
2、入队列，放到筒1里，很简单，放进去就行了；
3、出队列，把筒1的羽毛球全都折腾到筒2里，这时候筒2的最上面元素的就是入筒1的最底下元素
4、筒1的最底下的元素是最先放进去的
5、这时候从筒2拿出来最上面的元素就是最先进队列的元素，从而实现了先进先出。

### 代码

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        int a;
        if (stack2.empty())
        {
            //栈1的元素pop出来，入栈2
            while(!stack1.empty())
            {
                a = stack1.top();
                stack1.pop();
                stack2.push(a);
            }
        }
        a = stack2.top();
        stack2.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        int a;
        if (stack2.empty())
        {
            //栈1的元素pop出来，入栈2
            while(!stack1.empty())
            {
                a = stack1.top();
                stack1.pop();
                stack2.push(a);
            }
        }
        a = stack2.top();
        //stack2.pop();
        return a;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.empty() && stack2.empty())
        {
            return true;
        }
        return false;
    }

    stack<int> stack1;
    stack<int> stack2;
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