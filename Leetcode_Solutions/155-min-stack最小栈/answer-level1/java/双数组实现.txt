### 解题思路
双数组实现，

### 代码

```java
class MinStack {

   int[] data;
        int curLength = 0;
        int curMinLength = 0;
        int[] minStack;

        /**
         * initialize your data structure here.
         */
        public MinStack() {
            data = new int[10];
            minStack = new int[10];
        }

        public int[] grow(int minLength, int[] data) {
            int oldLength = data.length;
            int newLength = oldLength * 2;
            if (minLength > newLength) {
                newLength = minLength;
            }
            // 越界，注意新的长度超过data的长度会越界的
//            System.arraycopy(data, 0, data, 0, newLength);
            // 返回一个新的数组，如果长度超过原来的长度，则补充0
            return Arrays.copyOf(data, newLength);
        }

        public void push(int x) {
            if (curLength + 1 > data.length) {
                data = grow(curLength, data);
            }
            if (curMinLength + 1 > minStack.length) {
                minStack = grow(curMinLength, minStack);
            }
            data[curLength++] = x;
            // 必须带=如果不带，会出现重复的数据，在获取最小值时越界
            if (curMinLength == 0 || minStack[curMinLength - 1] >= x) {
                minStack[curMinLength++] = x;
            }
        }

        public void pop() {
            if (data[curLength - 1] == minStack[curMinLength - 1]) {
                curMinLength--;
            }
            curLength--;
        }

        public int top() {
            return data[curLength - 1];
        }

        public int getMin() {
            return minStack[curMinLength - 1];
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