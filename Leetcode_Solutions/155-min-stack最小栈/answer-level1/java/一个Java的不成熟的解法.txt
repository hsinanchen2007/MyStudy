### 解题思路

思路还是比较简单，对于栈就还是使用Java提供的`Stack`，主要考虑下面几个点：

1. 使用`min`保存当前最小值，使用`minCount`保存当前最小值有几个
2. 因为有可能有多个最小值，需要保证最小值被`pop`后不需要重新计算一次
3. 当最小值都被`pop`了，需要重新计算一次最小值和数量

![image.png](https://pic.leetcode-cn.com/c1f1fe831424424e19a0b4f90e6f2014c9823ad649b5d48653d962222edcd35f-image.png)


### 代码

```java
class MinStack {
    private int min;
    private int minCount;
    private Stack<Integer> stack;

    /**
     * initialize your data structure here.
     */
    public MinStack() {
        stack = new Stack<>();
        minCount = 0;
        min = Integer.MAX_VALUE;
    }

    private void putMin(int x) {
        if (x < min) {
            min = x;
            minCount = 0;
        }
        if (x == min) {
            minCount += 1;
        }
    }

    public void push(int x) {
        this.stack.push(x);
        putMin(x);
    }

    public void pop() {
        int i = stack.pop();
        if (i == min) {
            if (minCount > 1) {
                minCount -= 1;
                return;
            }
            min = Integer.MAX_VALUE;
            for (int x : stack) {
                putMin(x);
            }
        }
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return this.min;
    }
}
```