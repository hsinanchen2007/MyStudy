### 解题思路
 本地因为考虑到如果用索引记录栈顶,不及时清理掉List可能会导致List越来越大,因此直接用List的操作来完成

### 代码

```java
class MyStack {

    private List<Integer>data; 

    /** Initialize your data structure here. */
    public MyStack() {
        data = new ArrayList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        data.add(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        Integer n = data.get(data.size()-1);
        data.remove(n);
        return n;
    }
    
    /** Get the top element. */
    public int top() {
        return data.get(data.size()-1);
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return data.isEmpty();
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