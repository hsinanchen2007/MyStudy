打卡完毕!

### 代码

```java
class MyStack {
    Queue<Integer> list;

    /** Initialize your data structure here. */
    public MyStack() {
        list = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        list.add(x);
        int len = list.size();
        while(len>1){
            list.add(list.remove());
            len--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int temp = list.remove();
        return temp;
    }
    
    /** Get the top element. */
    public int top() {
        return list.peek();
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