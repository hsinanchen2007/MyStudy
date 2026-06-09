## 两种解法复杂度优缺点分析

### 解法一：压入O(1)弹出O(n)
push()时直接压入，与队列相同。
pop()时通过循环，将各个元素从队首取出放到队尾，直至原队尾元素暴露在队首，将其弹出即可。
top()与pop()同理，只不过当在队首得到原队尾元素后，要将其插回到队尾，恢复到top()前的状态，否则会影响pop()。

优点：由于压入O(1)，因此适合插入多的场景。
缺点：不仅pop()复杂度为O(n)，top()复杂度也是O(n)，不利于这两种操作多的场景。

代码：
```java
class MyStack {
    private Queue<Integer> q;

    /** 
     * Initialize your data structure here. 
     */
    public MyStack() {
        q = new LinkedList<Integer>();
    }
    
    /** 
     * Push element x onto stack. 
     */
    public void push(int x) {
        q.offer(x);   
    }
    
    /** 
     * Removes the element on top of the stack and returns that element. 
     */
    public int pop() {
        for(int i = 0; i < q.size() - 1; i++)
            q.offer(q.poll());
        return q.poll();
    }
    
    /** 
     * Get the top element. 
     */
    public int top() {
        for(int i = 0; i < q.size() - 1; i++)
            q.offer(q.poll());
        int t = q.peek();
        q.offer(q.poll());
        return t;
    }
    
    /** 
     * Returns whether the stack is empty. 
     */
    public boolean empty() {
        return q.size() == 0;
    }
}
```

### 解法二：压入O(n)弹出O(1)
为了让pop()和top()的复杂度为O(1)，则需要在压入的时候进行额外操作使元素在队列中的存储情况和栈相同。
第一个元素正常压入，**从第二个元素开始，每在队尾压入新元素后，就把它前面所有元素逐个从队首取出放到队尾**。

优点：适合pop()和top()操作多的场景。
缺点：不适合插入多的场景。

代码：
```java
class MyStack {
    private Queue<Integer> q;

    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.offer(x);
        int sz = q.size();
        while(sz > 1)
        {
            q.offer(q.poll());
            sz--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q.size() == 0;
    }
}
```