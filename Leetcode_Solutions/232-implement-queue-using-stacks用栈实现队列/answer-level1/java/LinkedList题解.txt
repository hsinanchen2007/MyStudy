### 解题思路
直接使用LinkedList中的方法即可。

### 代码

```java
class MyQueue {

    private Deque<Integer> list = null;

    /** Initialize your data structure here. */
    public MyQueue() {
        list = new LinkedList<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        list.offerLast(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return list.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return list.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return list.size() == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```