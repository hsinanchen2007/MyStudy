**思路**
首先，队列只能是先进先出，即从队头取出(poll)元素，然后往队尾插入(offer)元素。因此，如果我们要模拟栈，push就按照队列的offer操作执行。当执行pop操作的时候，目的是要取出队尾的元素，我们可以先将队列的n-1个元素先取出且逐个插入到队尾中，然后剩下一个元素就是我们所要的最开始队尾的元素。例如：队列$[3,2,1]$，右边是队头，左边是队尾，如果我们要执行栈的pop操作的时候，其实就是要将3弹出，这时候我们可以弹出1，插入到尾部，变成$[1,3,2]$，然后弹出2插入到尾部，变成$[2,1,3]$，最后弹出3即可，剩下$[2,1]$，也就实现了弹出3的效果。top操作同理。

```java
private Queue<Integer> queue;

    /** Initialize your data structure here. */
    public Problem225() {
        queue = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.offer(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        int n = queue.size();
        // 先队列头的n-1个元素去除逐个插入到队列尾部，最后再去队列头的元素就是原先尾的元素。
        for (int i = 0; i < n - 1; i++) {
            queue.offer(queue.poll());
        }

        return queue.poll();
    }

    /** Get the top element. */
    public int top() {
        int n = queue.size();
        // 先队列头的n-1个元素去除逐个插入到队列尾部，最后再去队列头的元素就是原先尾的元素。
        for (int i = 0; i < n - 1; i++) {
            queue.offer(queue.poll());
        }

        int top = queue.poll();
        queue.offer(top);
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
```