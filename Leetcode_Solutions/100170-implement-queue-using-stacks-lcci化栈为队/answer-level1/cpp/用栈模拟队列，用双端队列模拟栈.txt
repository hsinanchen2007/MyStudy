### 解题思路
这道题 是用两个栈来模拟队列，但是不允许使用现成的栈，所以我用两个一端输入输出受限的双端队列来模拟栈。
在栈模拟队列的过程中：
push操作就是直接push进去就可以
pop操作由于需要弹出栈底元素，所以先把元素挪到另一个栈，取出该元素，再把剩下元素放回原位。
其他操作都一样

### 代码

```cpp
class MyQueue {
public:
      deque<int> s1;
      /*
       s1.push_front() 插入
       s1.pop_front()出栈
      */
      deque<int> s2;
      //s2.push_front jin
      //s2.pop_front  chu
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
         s1.push_front(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1.empty()){
            int top=s1.front();
            s1.pop_front();
            s2.push_front(top);
        }
        int num=s2.front();
       s2.pop_front();
       while(!s2.empty()){
           int top=s2.front();
            s2.pop_front();
            s1.push_front(top);
       }
       return num;
    }
    
    /** Get the front element. */
    int peek() {
      return s1.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return s1.empty();
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