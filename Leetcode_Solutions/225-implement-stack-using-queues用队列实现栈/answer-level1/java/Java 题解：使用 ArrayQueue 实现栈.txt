### 解题思路
这个题目难度是【简单】，但是题目要求还是要注意的，就是必须使用**队列的基本操作**去实现栈。记住这点就好了。

下面结合代码简单的注释一下：

```java
class MyStack {

    // 我们使用 java 的双端队列 Deque 实现栈, 但是不要用 Deque 的栈操作方法(这个谨记!!!).
    // Deque 符合队列操作(FIFO)的基本方法就是 add (亦即 addLast) 和 poll (亦即 pollFirst);
    Deque<Integer> st;

    /** Initialize your data structure here. */
    public MyStack() {
        st = new ArrayDeque<>();
    }

    /** Push element x onto stack. */
    // 实现的关键是 push 方法, 我们只要确定每次插入新的元素后确保该新元素在队列头部即可. 方法就是执行一次循环将插入尾部的新元素拿到队列前面即可!
    // push 方法时间复杂度 O(n), 其他方法时间复杂度都是 O(1).
    public void push(int x) {
        st.addLast(x);
        int sz = st.size();
        while (sz > 1) {
            st.addLast(st.pollFirst());
            sz--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return st.pollFirst();
    }

    /** Get the top element. */
    public int top() {
        return st.peekFirst();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return st.isEmpty();
    }
}
```


