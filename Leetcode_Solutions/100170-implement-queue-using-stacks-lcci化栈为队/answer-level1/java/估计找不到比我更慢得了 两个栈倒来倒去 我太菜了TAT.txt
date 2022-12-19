### 解题思路
此处撰写解题思路

### 代码

```java
class MyQueue {
    private Stack<Integer> InStack;//存数栈
    private Stack<Integer> OutStack;//辅助栈
    /** Initialize your data structure here. */
    public MyQueue() {
        InStack = new Stack<>();
        OutStack = new Stack<>();

    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        InStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        //取出数并按序存入辅助栈再pop 完毕后再从辅助栈压入数栈
        while(!InStack.empty()){
            OutStack.push(InStack.pop()); 
        }
        int pop = OutStack.pop();
        while(!OutStack.empty()){
            InStack.push(OutStack.pop()); 
        }
        return pop;
        
    }
    
    /** Get the front element. */
    public int peek() {
        while(!InStack.empty()){
            OutStack.push(InStack.pop()); 
        }
        int peek = OutStack.peek();
        while(!OutStack.empty()){
            InStack.push(OutStack.pop()); 
        }
        return peek;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return InStack.empty();
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