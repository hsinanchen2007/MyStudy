先上结果：

>执行结果：通过 显示详情
>
>执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
>
>内存消耗 :37.1 MB, 在所有 Java 提交中击败了5.41%的用户



因为ArrayDeque是从后往前插入的数组，有头、尾两个引用保证快速出入栈。

```
//leetcode submit region begin(Prohibit modification and deletion)
class MyStack {

    Deque<Integer> ad = new ArrayDeque<>();

    /** Initialize your data structure here. */
    public MyStack() {


    }

    /** Push element x onto stack. */
    public void push(int x) {
        ad.offerFirst(x);

    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return ad.pollFirst().intValue();
    }

    /** Get the top element. */
    public int top() {
        return ad.peekFirst().intValue();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return ad.isEmpty();
    }
}
```
