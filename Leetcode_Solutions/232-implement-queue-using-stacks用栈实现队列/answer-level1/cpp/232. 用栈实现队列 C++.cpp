### 解题思路
1.使用两个栈进行交替使用。
2.入队列时先入栈a，出队的时候先检查栈a是否为空，若有则逐个出栈，再压入栈b直到栈a为空，此时再出栈b中的元素便是最先入队的元素。
3.检查队列是否为空时，两个栈都为空时队列才为空。

### 代码

```cpp
class MyQueue {
private:
    stack <int> nums_a;
    stack <int> nums_b;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!nums_b.empty()) {
            nums_a.push(nums_b.top());
            nums_b.pop();
        }
        nums_a.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!nums_a.empty()) {
            nums_b.push(nums_a.top());
            nums_a.pop();
        }
        int num = nums_b.top();
        nums_b.pop();
        return num;
    }

    /** Get the front element. */
    int peek() {
        while (!nums_a.empty()) {
            nums_b.push(nums_a.top());
            nums_a.pop();
        }
        return nums_b.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return nums_a.empty() && nums_b.empty();
    }

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