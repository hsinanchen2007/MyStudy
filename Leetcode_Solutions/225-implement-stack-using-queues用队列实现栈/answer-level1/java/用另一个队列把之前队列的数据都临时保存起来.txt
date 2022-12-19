### 解题思路
我只能想到用另外一个队列把前一个队列的都保存起来，为了提高（打卡）我只能把题解发出来了。

### 代码

```java
class MyStack {
    private Queue<Integer> queue;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new PriorityQueue();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.offer(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        Queue<Integer> tmpQueue = new PriorityQueue();
        int len = queue.size() - 1;
        for(int i = 0; i < len; i++) {
            tmpQueue.offer(queue.poll());
        }
        int top = queue.poll();
        len = tmpQueue.size();
        for(int i =0; i < len; i++) {
            queue.offer(tmpQueue.poll());
        }

        return top;
    }
    
    /** Get the top element. */
    public int top() {
        Queue<Integer> tmpQueue = new PriorityQueue();
        int len = queue.size() - 1;
        for(int i = 0; i < len; i++) {
            tmpQueue.offer(queue.poll());
        }
        int top = queue.poll();
        len = tmpQueue.size();
        for(int i =0; i < len; i++) {
            queue.offer(tmpQueue.poll());
        }
        queue.offer(top);

        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
```