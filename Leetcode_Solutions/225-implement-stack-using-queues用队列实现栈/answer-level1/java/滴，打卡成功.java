### 解题思路
使用两个队列，q1存放添加的元素，由于是先进先出，所以在pop的时候，将q1队列中前n-1个元素放入q2，将最后一个元素弹出。
完成之后q1和q2互换身份。

### 代码

```java
class MyStack {
 Queue<Integer> q1 = new LinkedList();
    Queue<Integer> q2 = new LinkedList();
    /** Initialize your data structure here. */
    int x;
    public MyStack() {

    }

    /** Push element x onto stack. */
    public void push(int x) {
        q1.offer(x);
        this.x = x;

    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        while (q1.size() > 1){
            x = q1.poll();
            q2.offer(x);
        }
        int num =  q1.poll();
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
        return num;
        
    }

    /** Get the top element. */
    public int top() {
        return x;
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