### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
public:
     /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    if (push_stack_.empty() && pop_stack_.empty()) {
      peek_ = x;
    }
    push_stack_.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    while (!push_stack_.empty()) {
      auto curr = push_stack_.top();
      push_stack_.pop();
      pop_stack_.push(curr);
    }
    int pop_ele = pop_stack_.top();
    pop_stack_.pop();
   if (!pop_stack_.empty()) {
      peek_ = pop_stack_.top();
    }
    while (!pop_stack_.empty()) {
      auto curr_push = pop_stack_.top();
      push_stack_.push(curr_push);
      pop_stack_.pop();
    }
    return pop_ele;
  }

  /** Get the front element. */
  int peek() { return peek_; }

  /** Returns whether the queue is empty. */
  bool empty() { return pop_stack_.empty() && push_stack_.empty(); }

private:
  std::stack<int> pop_stack_;
  std::stack<int> push_stack_;
  int peek_ = 0;
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