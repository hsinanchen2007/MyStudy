### 解题思路


### 代码

```java
class MyQueue {
    private Stack<Integer> a;//输入栈
    private Stack<Integer> b;//输出栈
    /** Initialize your data structure here. */
    public MyQueue() {
     a=new Stack<>();
     b=new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
         a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
    //如果b输出栈为空，a输入栈将所有元素放入b中
    if(b.isEmpty())
    {
        while(!a.isEmpty())
             b.push(a.pop());
    }
    //b不空就直接输出
    return b.pop();
    }
    
    /** Get the front element. */
    public int peek() {
    if(!b.isEmpty())
      return b.peek();
    else
    {
        while(!a.isEmpty())
             b.push(a.pop());
        return b.peek();
    }
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
     return a.isEmpty() && b.isEmpty();
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