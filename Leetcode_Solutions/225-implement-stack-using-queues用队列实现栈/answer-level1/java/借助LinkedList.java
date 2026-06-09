### 解题思路

使用LinkedList,单向插入和删除

### 代码

```java
class MyStack {

    private LinkedList<Integer> list;

    /** Initialize your data structure here. */
    public MyStack() {
        list=new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        list.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
       return list.removeLast();
    }

    /** Get the top element. */
    public int top() {
        return list.getLast();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return list.isEmpty();
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