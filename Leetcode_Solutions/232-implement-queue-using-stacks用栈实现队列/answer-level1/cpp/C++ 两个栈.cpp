### 解题思路
使用两个栈；一个栈用来push，另一个栈用来pop

### 代码

```cpp
class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        en.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!this->empty()) {
            int ret = this->peek();
            de.pop();
            return ret;
        }
        return -1;
    }

    /** Get the front element. */
    int peek() {
        if(!this->empty()) {
            if(de.empty()) {
                while(!en.empty()) {
                    int elem = en.top();
                    de.push(elem);
                    en.pop();
                }
            }
            return de.top();
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return en.empty() && de.empty();
    }
  private:
    stack<int> en;
    stack<int> de;
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