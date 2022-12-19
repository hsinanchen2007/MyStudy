```
class MyStack {
    Queue<Integer> q;
    
    /** Initialize your data structure here. */
    public MyStack() {
        q = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
       for(int i = 0; i < q.size() - 1; i++) {
            q.add(q.poll());
        }
        return q.poll();
    }
    
    /** Get the top element. */
    public int top() {
        for(int i = 0; i < q.size() - 1; i++) {
            q.add(q.poll());
        }
        int temp = q.poll();
        q.add(temp);
        return temp;
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
内存消耗有点多呢。。
![image.png](https://pic.leetcode-cn.com/398548924531036c97d00f30b1c1e8d0e650c96b9586ae731b44026143899955-image.png)
