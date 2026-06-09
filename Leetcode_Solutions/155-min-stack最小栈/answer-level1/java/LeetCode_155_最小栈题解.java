### 解题思路

- 重点：

测试用例中的数量过大，主要时间估计会耗费在Push元素时，Stack的扩充上。所以我把初始的数组大小改大了一点，大概10w就通过了。但是执行时长会慢。

### 代码

```java
class MinStack {

    private int[] val;

    private final static int DEFAULT_LENGTH = 100000;

    private final static int ENLARGE_SIZE = 100;

    private int size;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        size = 0;
        val = new int[DEFAULT_LENGTH];
    }

    public void push(int x) {
        if (size + 1 >= DEFAULT_LENGTH) {
            val = enlarge(val);
        }

        val[size++] = x;
    }

    private int[] enlarge(int[] val) {
        return Arrays.copyOf(val, val.length + ENLARGE_SIZE);
    }

    public void pop() {
        val[size] = 0;
        size --;
    }

    public int top() {
        return val[size - 1];
    }

    public int getMin() {
        int minNum = val[0];
        for (int i = 0; i < size; i++) {
            if (minNum > val[i]) {
                minNum = val[i];
            }
        }
        return minNum;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```