**使用数组 维护一个最小栈**
```
class MinStack {

    Integer[] stack;    // 数组栈
    int capacity = 10;  // 容量
    int topIndex = -1;  // 栈顶索引
    int minIndex = 0;   // 最小值索引

    /** initialize your data structure here. */
    public MinStack() {
        stack = new Integer[capacity];
    }

    public void push(int x) {
        if ((topIndex + 1) == capacity) {
            grow();
        }
        topIndex++;
        stack[topIndex] = x;
        refreshByPush();
    }

    public void pop() {
        /** if ((topIndex + 1) < (capacity / 2)) {
            reduce();
        } */
        stack[topIndex] = null;
        topIndex--;
        if (topIndex + 1 == minIndex) {
            minIndex = 0;
            refreshMin();
        }
    }

    public int top() {
        if (topIndex < 0) {
            throw new IllegalStateException("空栈");
        }
        return stack[topIndex];
    }

    public int getMin() {
        if (topIndex < 0) {
            throw new IllegalStateException("空栈");
        }
        return stack[minIndex];
    }

    private void grow() {
        capacity = capacity + (capacity >> 1);
        Integer[] newStack = new Integer[capacity];
        System.arraycopy(stack, 0, newStack, 0, topIndex + 1);
        stack = newStack;
    }

    private void reduce() {
        capacity = capacity >> 1;
        Integer[] newStack = new Integer[capacity];
        System.arraycopy(stack, 0, newStack, 0, topIndex + 1);
        stack = newStack;
    }

    private void refreshByPush() {
        if (stack[minIndex] > stack[topIndex]) {
            minIndex = topIndex;
        }
    }

    private void refreshMin() {
        for (int i = minIndex; i < topIndex + 1; i++) {
            if (stack[minIndex] > stack[i]) {
                minIndex = i;
            }
        }
    }

    public int size() {
        return topIndex + 1;
    }

    public int capacity() {
        return capacity;
    }
}
```
