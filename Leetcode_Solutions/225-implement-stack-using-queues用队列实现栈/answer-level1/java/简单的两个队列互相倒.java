### 解题思路
两个队列互相倒数据。
class MyStack {
    private Queue<Integer> q1;
    private Queue<Integer> q2;

    /** Initialize your data structure here. */
    public MyStack() {
        q1 = new LinkedBlockingQueue<>();
        q2 = new LinkedBlockingQueue<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        if (!q1.isEmpty()) {
            q1.add(x);
        } else {
            q2.add(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        Queue<Integer> cur;
        Queue<Integer> other;
        if (q1.isEmpty()) {
            cur = q2;
            other = q1;
        } else {
            cur = q1;
            other = q2;
        }

        while (cur.size() > 1) {
            other.add(cur.remove());
        }

        return cur.remove();
    }

    /** Get the top element. */
    public int top() {
        int h = pop();
        push(h);
        return h;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return q1.isEmpty() && q2.isEmpty();
    }
}

