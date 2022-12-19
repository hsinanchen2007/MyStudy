
top() : 利用top记录栈顶的元素
push() : 在尾部加上元素，标记top
pop() : 将队列首部 移动 size()-1个到尾部，并删除队首（此时队首就是队尾，也就是栈顶）
empty() ： 不用多说

```java
class MyStack {
    Queue<Integer> q = null;
    private int top = 0;
    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.offer(x);
        top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int size = q.size();
        for(int i = 1; i < size; i++){
            top = q.poll();
            q.offer(top);
        }
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.isEmpty();
    }
}
```