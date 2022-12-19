### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {
    LinkedList stack;
    LinkedList tem;
    /** Initialize your data structure here. */
    public MyStack() {
        stack = new LinkedList();
        tem = new LinkedList();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        stack.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        //找到队列尾部
        while(stack.size()>1){
            tem.add(stack.poll());
        }
        int top = (int)stack.poll();
        stack = tem;
        tem = new LinkedList();
        return top;
    }
    
    /** Get the top element. */
    public int top() {
        //找到队列尾部
        while(stack.size()>1){
            tem.add(stack.poll());
        }
        int top = (int)stack.peek();
        //将队列尾部加入队列
        tem.add(top);
        
        stack = tem;
        tem = new LinkedList();
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return stack.isEmpty();
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