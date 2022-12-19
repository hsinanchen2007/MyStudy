### 解题思路
栈是后进先出(Last In First Out)的数据结构，而队列是先进先出的数据结构(First In First Out).
为了使用队列模拟栈，我们让队列的队首(front)存储要模拟的栈的顶部(top)元素。

```
    /*
     * ----------------------
     * 队首               队尾
     * ----------------------
     * 栈顶               栈底
     */
```

进栈：
假设当前队列已经存储了N个元素。当新的元素入栈时，新的元素从队尾进入，此时队列里有N+1个元素。
为了让新的元素到达队首，即模拟的栈的顶部，将队列的前N个元素出队列，并按出队列的顺序从队尾进入队列。

出栈：
让队列的队首元素出队列，即模拟的栈的顶部元素。

记元素个数为n，
进栈的时间复杂度：O(n)
出栈的时间复杂度：O(1)

### 代码

```cpp

class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {
      
  }
  
  /** Push element x onto stack. */
  void push(int x) {
    /*
     * ----------------------
     * front             back
     * ----------------------
     * stack.top
     */
    int siz = q.size();
    q.push(x);
    for (int i = 0; i < siz; ++i) {
      q.push(q.front()); 
      q.pop();
    }
      
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int target = top();
    q.pop();
    return target;
  }
  
  /** Get the top element. */
  int top() {
    return q.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }
private:
  queue<int> q;
};

```