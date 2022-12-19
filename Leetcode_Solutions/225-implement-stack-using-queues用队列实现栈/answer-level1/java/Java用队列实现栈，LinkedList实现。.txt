### 解题思路
用Java里的`LinkedList`来实现，成员变量为`LinkedList`对象`ll`和记录栈长度的`length`。
构造方法就是new一个`LinkedList`对象,初始化长度`length = 0`。


### 代码

```java
class MyStack {

    private LinkedList<Integer> ll;
    private int length;
    
    /** Initialize your data structure here. */
    public MyStack() {
        this.ll = new LinkedList<>();
        this.length = 0;
    }

    /** Push element x onto stack. */
    public void push(int x) {
        ll.push(x);
        length++;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        length--;
        Integer top = ll.getFirst();
        ll.removeFirst();
        return top;
    }

    /** Get the top element. */
    public int top() {
        Integer top = ll.getFirst();
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return length == 0;
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