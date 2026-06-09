### 解题思路
一、增加数据无需考虑
二、pop和peek需要考虑栈二的状态，优先输出栈二中的数据，如果为空则将栈一的数据全部拷过来，在输出栈二的数据
### 代码

```java
class MyQueue {
    Stack<Integer> push;
    Stack<Integer> pop;
    int size = 0;
    /** Initialize your data structure here. */
    public MyQueue() {
        push = new Stack<>();
        pop = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        push.push(x);
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (pop.empty()) {
            pushToPop();
        }
        size--;
        return pop.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (pop.empty()) {
            pushToPop();
        }
        return pop.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return size == 0;
    }

    private void pushToPop() {
        while (!push.empty()) {
            pop.push(push.pop());
        }
    }
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */
```