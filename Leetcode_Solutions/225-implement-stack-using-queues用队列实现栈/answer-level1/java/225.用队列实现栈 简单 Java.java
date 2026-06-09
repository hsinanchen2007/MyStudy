### 解题思路
本题较为简单，只是考察了队列和栈这两种基本数据结构的特点，队列（先进先出FIFO），栈（后进先出LIFO）。要用队列实现栈也很简单，用一个队列即可，每一次压栈操作（等同于队列入队，然后将该入队元素前面的元素依次出队再入队，使得压栈的元素放在队列最前头，这样就能符合栈后进先出的特点了）。
本题在于我学Java没多久，还没知道Java队列的实现，查阅资料后发现，LinkedList实现了Queue接口，然后队列操作有入队offer()/add(),出队poll()/remove(),返回队头元素peek()/element(),返回大小size()和检查是否为空isEmpty()。其中有两种相同功能的操作中，前者在方法失败是会抛出false/null/null而后者会抛出异常。

### 代码

```java
import java.util.LinkedList;
import java.util.Queue;
class MyStack {
    Queue<Integer> queue;
    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.offer(x);
        for(int i = 1; i < queue.size(); i++) {
            queue.offer(queue.poll());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return queue.peek();
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