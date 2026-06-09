### 解题思路
#####此题为简单，算是极其入门的题目，如果有同学做这道题需要看题解的话，不妨先花10分钟回忆一下队列和栈的定义
队列：先入先出
栈：先入后出

要用先入先出的队列模拟先入后出的栈，核心思想就是出栈的时候，判断是不是最后一个了，也就是出完队列后，这个元素是不是最后一个，如果是，返回，如果不是，则继续出队，直到最后一个

### 代码

```java
public class MyStack {

    Deque<Integer> in;
    Deque<Integer> out;
    /** Initialize your data structure here. */
    public MyStack() {
        in = new ArrayDeque<>();
        out = new ArrayDeque<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        in.addLast(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while (! in.isEmpty()) {
            int getValue = in.removeFirst();

            if (in.isEmpty()) {
                in = out;
                out = new ArrayDeque<>();
                return getValue;
            }
            out.addLast(getValue);
        }
        return  -1;
    }

    /** Get the top element. */
    public int top() {
        while (! in.isEmpty()) {
            int getValue = in.removeFirst();
            out.addLast(getValue);
            
            if (in.isEmpty()) {
                in = out;
                out = new ArrayDeque<>();
                return getValue;
            }
        }
        throw new NullPointerException();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return in.isEmpty();
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