### 解题思路
此处撰写解题思路

### 代码

```java
class MyStack {
    Queue<Integer> q=new LinkedList();
    /** Initialize your data structure here. */
    public MyStack() {

    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        q.offer(x);
        for(int i=1;i<q.size();i++)//实现栈后进先出
        {
            q.offer(q.remove());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return(q.poll());//返回第一个队列元素并删除 实现出栈
    }
    
    /** Get the top element. */
    public int top() {
        return q.peek();//返回队列第一个元素
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