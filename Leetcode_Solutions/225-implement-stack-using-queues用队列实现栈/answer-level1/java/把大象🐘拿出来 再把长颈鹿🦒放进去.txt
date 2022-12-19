### 解题思路
这道题考查【队列】和【栈】的异同，队列先进先出，栈后进先出，用队列模拟栈，就是要让“先进去的”变成“后进去的”
具体做法是在每次push进一个元素后，将队列中原有的先进去的取出来，再依次放进当前元素后面，这样就实现了越新的排在了越前面，
取出的时候，最前面的实际是最后进入的，就实现了栈的效果

### 代码

```java
class MyStack {
    
    Queue<Integer> queue;

    /** Initialize your data structure here. */
    public MyStack() {
        queue = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        int n = queue.size();
        queue.add(x);
        for(int i=0; i<n; i++) {
            queue.add(queue.remove());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.remove();
    }
    
    /** Get the top element. */
    public int top() {
        return queue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.size() == 0;
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