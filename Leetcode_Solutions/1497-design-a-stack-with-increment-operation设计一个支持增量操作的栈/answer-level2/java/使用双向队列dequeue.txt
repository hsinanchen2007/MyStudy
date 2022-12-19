### 解题思路
利用双向队列来实现栈

### 代码

```java
class CustomStack {

    private int maxSize;
    private Deque<Integer> queue;

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        queue = new LinkedList<>();
    }

    public void push(int x) {
        if (queue.size() == maxSize) return;
        queue.push(x);
    }

    public int pop() {
        if (queue.isEmpty()) return -1;
        return queue.pop();
    }

    public void increment(int k, int val) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            if (i >= size - k) queue.addLast(queue.pop() + val); // k个栈底元素
            else queue.addLast(queue.pop()); // 其他元素
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */
```