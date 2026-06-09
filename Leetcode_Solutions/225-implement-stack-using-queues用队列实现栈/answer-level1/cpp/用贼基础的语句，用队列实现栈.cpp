解释得比较废话，但是也比较全面

本题通过两个队列的循环使用，来实现栈的作用

先明白

队列（queue）是一种先入先出的数据结构（FIFO）

栈（stack）是一种后入先出的数据结构（LIFO）

![queue.png](https://pic.leetcode-cn.com/da6fd9b63263d94232975fc560f6570a9f00de797822721f751b720539579710-queue.png)
![stack.png](https://pic.leetcode-cn.com/1c721787c6fc8377f56d4c7fb6a22f544368e571b37652ed20311f715c666efd-stack.png)

以上为两个数据结构的图形

开始对比
1. push： 两种数据结构的push方法相同，都是在数据的后面压入数据。
2. pop： 队列的pop是从前面开始，即从数据的front部分； 而栈的pop从后面开始，即从数据的top部分
3. top： 操作位置与pop类似，只是只返回值，不删除数据。
由此可知，我们本题的关键是实现pop 和top的操作。我们通过两个队列的相互配合来实现栈。
例如，若a队列存有数据，将数据除了最后一项全部推入b队列，由于是先入先出，数据的顺序不变。a队列还剩下一个数据，当队列的数据仅剩一个时，该数据既是队列的第一个数据，也是队列的最后一个数据，通过pop（）和front（）函数的调用，可以产生相应的栈的pop（）和top（）的作用。
```
class MyStack {
public:
    /** Initialize your data structure here. */
    queue <int> q1;
    queue <int> q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) { //保证数据全部push到同一个队列
       if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())
        {
            int len = q2.size();
            for(int i = 0; i<len - 1; ++i) //将有数据的队列的数据除了最后一个以外，全部push到另一个队列。
            {
                q1.push(q2.front());
                q2.pop();
            }
            int a=q2.front();
            q2.pop();
            return a;
            
        }
        else
        {
            int len = q1.size();
            for(int i = 0; i<len - 1; ++i) //同上
            {
                q2.push(q1.front());
                q1.pop();
            }
            int a=q1.front();
            q1.pop();
            return a;
            
        }
        
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())
        {
            //q2.size()
            int len = q2.size();
            for(int i = 0; i<len - 1; ++i) //同上
            {
                q1.push(q2.front());
                q2.pop();
            }
            int a = q2.front();
            q1.push(q2.front());
            q2.pop();
            return a;
            
        }
        else
        {
            int len = q1.size();
            for(int i = 0; i<len-1; ++i) //同上
            {
                q2.push(q1.front());
                q1.pop();
            }
            int a = q1.front();
            q2.push(q1.front());
            q1.pop();
            return a;
            
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
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