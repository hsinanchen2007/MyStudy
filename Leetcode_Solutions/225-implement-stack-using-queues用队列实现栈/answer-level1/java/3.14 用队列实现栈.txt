### 解题思路
1.栈是先进后出  队列是先进先出  如果用队列去写栈 就得让队列在push的时候颠倒一下 然后输出的时候才能和栈一样
2.在入栈时，将新元素压入队列后，将新元素之前的队列元素重新入队，使得新元素位于队头，在出栈（出队）时该新元素第一个弹出。
3，具体的代码是
当新入一个元素.offer时，进入循环，将以前的元素已经入队列的元素再重新入队列（.offer）

### 代码

```java

class MyStack {
    Queue<Integer> queue;
    // 根据官方推荐，使用ArrayDeque作为队列
    public MyStack() {
        queue = new ArrayDeque<>();
    }
    
    // 入栈时，将新元素x进入队列后，将新元素x之前的所有元素重新入队，此时元素x处于队头
    public void push(int x) {
        queue.offer(x);
        int size = queue.size();
        for (int i = 0; i < size - 1; i++) {
            queue.offer(queue.poll());
        }
    }
    
    // 出栈pop操作和检查栈顶元素的top操作在调用队列相应方法前，需要检查队列是否为空，
    // 否则可能产生空指针异常
    public int pop() {
        if (queue.isEmpty()) {
            throw new RuntimeException("EMPTY STACK");
        }
        return queue.poll();
    }

    public int top() {
        if (queue.isEmpty()) {
            throw new RuntimeException("EMPTY STACK");
        }
        return queue.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
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