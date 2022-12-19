### 解题思路
队列的特点是新添加的元素在后边，出队的元素在前面
栈的特点是新添加的元素在后边，出队的元素也在后边
所以我们只需要实现队列每次添加的元素实在最前面就好了！
实现思路:
    1.入队新元素
    2.依次将队列原先元素全部出队入队到队列最后面
### 代码

```java
class MyStack {

    private Queue<Integer> q = new LinkedList<>();
    
    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x); 
        for(int i = 1; i<q.size(); i++){
            q.add(q.remove());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.remove();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
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