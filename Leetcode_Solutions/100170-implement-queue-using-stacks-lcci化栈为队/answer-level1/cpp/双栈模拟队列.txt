首先明确队列和栈的区别就是出队与出栈的顺序是相反的，那么我们可以采用另一个栈将出栈顺序再次翻转就可以让其出栈顺序与出队顺序一致。
所以采用两个栈 push_stack 和 pop_push，其中，push_stack 只负责入队操作，即只有在 push 时，将 value 压入该栈，pop_stack 只负责出队操作，即在 pop 或 peek 时，从该栈弹出元素，但是由于该栈只出不进，则会导致该栈为空的情况，这时我们只需要将 push_stack 中的元素依次弹出并压入 pop_stack 中即可。
![图片.png](https://pic.leetcode-cn.com/22bddbae8c24e32242bf7d6aef7e7752ef54968df3f4547f6bae7e7526f4f60b-%E5%9B%BE%E7%89%87.png)

```
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        push_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }

        if (pop_stack.empty()) {
            return -1;
        }

        int ret = pop_stack.top();
        pop_stack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (pop_stack.empty()) {
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }

        if (pop_stack.empty()) {
            return -1;
        }

        return pop_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pop_stack.empty()  && push_stack.empty();
    }

private:
    stack<int> push_stack;
    stack<int> pop_stack;
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
