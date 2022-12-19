### 解题思路
ArrayList top 列表的最后一个元素，pop 返回 top，push 添加到末尾，empty 直接判断 list 是否为空

### 代码

```java
class MyStack {
    List<Integer> queue = new ArrayList<>();
    
    /** Initialize your data structure here. */
    public MyStack() {
        
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.remove(queue.size()-1);
    }
    
    /** Get the top element. */
    public int top() {
        return queue.get(queue.size()-1);
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
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