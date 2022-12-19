### 解题思路
两个栈操作
### 代码

```java
class MyQueue {

    Stack<Integer> stack1 = null;
    Stack<Integer> stack2 = null;


    /** Initialize your data structure here. */
    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack1.add(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {

        if(!stack2.isEmpty()){
            return stack2.pop();
        }

        while(!stack1.isEmpty()){
            stack2.add(stack1.pop());
        }

        return stack2.pop();

    }
    
    /** Get the front element. */
    public int peek() {

         if(!stack2.isEmpty()){
            return stack2.peek();
        }

        while(!stack1.isEmpty()){
            stack2.add(stack1.pop());
        }

        return stack2.peek();

    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {

        return stack1.isEmpty() && stack2.isEmpty();

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