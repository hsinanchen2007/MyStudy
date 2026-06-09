### 解题思路
我们知道：**同一段序列，分别存进一个栈和一个队列，那么出栈序列T和出队序列S顺序刚好是相反的。**
那么，假如我们有两个栈的话，一段序列`list`通过第一个栈后，再压入第二个栈，这时第二个栈的出栈序列应该和`list`压入某个队列后的出对序列是一样的。
既然如此，我们用两个栈模拟队列时，一个栈专门用来存入数据，记为`StackWrite`；一个栈专门用来读取数据，记为`StackRead`。基于上面的结论，我们每次入队时，就把数据压入`StackWrite`，每次读数据时，就把`Stack
Write`中的数据再压入`StackRead`，这时`StackRead`中的**栈顶元素**就是我们所期望的**队首元素**。

在出队的时候，要注意一点，如果`StackRead`中有数据，那么就直接取`StackRead`的栈顶元素，如果`StackRead`为空，再考虑把`StackWrite`中的元素压入`StackRead`，再取`StackRead`的栈顶元素。

### 代码

```java
class MyQueue {

    Stack<Integer> stackWrite;   // 存数据
    Stack<Integer> stackRead;   // 读数据

    /** Initialize your data structure here. */
    public MyQueue() {
        stackWrite = new Stack<>();
        stackRead = new Stack<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stackWrite.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        peek();
        return stackRead.pop();
    }
    
    /** Get the front element. */
    public int peek() {
        if (!stackRead.isEmpty()) {
            return stackRead.peek();
        }
        while (!stackWrite.isEmpty()) {
            stackRead.push(stackWrite.pop());
        }
        return stackRead.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stackRead.isEmpty() && stackWrite.isEmpty();
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