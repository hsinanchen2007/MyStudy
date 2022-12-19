### 解题思路
此处撰写解题思路
此题解法不止一种，这里说一种常见的解法。
栈是后进先出的数据结构，队列是先进先出的数据结构。所以要想有队列实现栈，常见的做法是用两个队列来代替栈
进栈时直接压入队列q1
出栈时，就需要用到了队列q2
要想用队列实现后进先出，那就是把前面的元素先存起来，然后把最后一个元素弹出去
### 代码

```java
class MyStack {
    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();
    private int top;

    /** Initialize your data structure here. */
    public MyStack() {

    }

    /** Push element x onto stack. */
    public void push(int x) {
        top = x;
        q1.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while (q1.size()>1){
            top = q1.remove();
            q2.add(top);
        }
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return q2.remove();
    }

    /** Get the top element. */
    public int top() {
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty();
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