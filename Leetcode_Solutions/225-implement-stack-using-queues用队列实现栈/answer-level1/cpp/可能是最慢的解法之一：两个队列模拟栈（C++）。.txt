### 解题思路
用两个队列 q1, q2 来实现栈，在栈非空情况下，q1 和 q2 总有一个为空.
私有变量 capacity 指示当前元素数，t 指示当前栈顶元素。
不妨设当前 q1 不空 q2 空：
当需要 push(x) 时，将元素 x 加入 q1，capacity + 1， t = x。
当需要 pop 时，依次将 q1 中的非末尾元素的 front 加入 q2，t = front，当遇到末尾元素时，返回该元素。
当需要 top 元素时，返回 t。
当需要判断栈是否为空时，只需看 capacity 的值是否为 0。

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        capacity = 0;
        t = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        t = x;
        if (!q2.empty()) q2.push(x);
        else q1.push(x);
        capacity++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        capacity--;
        if (!q1.empty()) return clearQueue(q1, q2);
        else return clearQueue(q2, q1);
    }
    
    int clearQueue(queue<int>& q1, queue<int>& q2) {
        int ret = 0;
        while (!q1.empty()) {
            ret = q1.front();
            q1.pop();
            if (!q1.empty()) {
                t = ret;
                q2.push(ret);
            }
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return capacity == 0;
    }
    
private:
    int capacity, t;
    queue<int> q1;
    queue<int> q2;
};
