用栈模拟队列时，我们可以把栈底看做队列尾部，把栈顶看做队列头部。
这样，只要改变push的操作逻辑即可。而pop，peek，empty的操作就可以直接用栈本身的操作就可以完成。
这里队列的push需要把对象放到栈底，这个操作可以借助一个辅助栈来完成。
先把主栈里原来的所有对象都依次pop并push到辅助栈里。
然后把新对象push到主栈里面，再把辅助栈里的所有对象依次pop并push回主栈即可。

```
class MyQueue {

    /** Initialize your data structure here. */
    Stack<Integer> stack = new Stack<Integer>();
    
    public MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        if (!stack.empty()) {
            Stack<Integer> stack1 = new Stack<Integer>();
            while(!stack.empty()) {
                stack1.push(stack.pop());
            };
            stack.push(x);
            while(!stack1.empty()) {
                stack.push(stack1.pop());
            };
        } else {
            stack.push(x);
        };
    };
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        return stack.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        return stack.peek();
        
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack.empty();
    }
}
```
