### 解题思路
使用两个栈结构模拟队列实现，inStack作为辅助，outStack实现队列的所有操作。
对于push操作：
- 将outStack中的元素逐个弹出并压入inStack中，直到outStack为空；
- 将要插入的元素压入inStack（此时在inStack中，要插入的元素x位于栈顶）；
- 将inStack中的元素逐个弹出并压入outStack中，直到inStack为空（此时在outStack中，要插入的元素x位于栈底）；

复杂操作都在push函数中实现了，outStack就相当于这个队列。接下来的pop、peek、empty操作都可以用outStack实现。
### 代码

```java
class MyQueue {
    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    /** Initialize your data structure here. */
    public MyQueue() {
        inStack = new Stack<Integer>();
        outStack = new Stack<Integer>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        while(!outStack.empty()){
            inStack.push(outStack.pop());
        }
        inStack.push(x);
        while(!inStack.empty()){
            outStack.push(inStack.pop());
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return outStack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return outStack.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return outStack.empty();
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