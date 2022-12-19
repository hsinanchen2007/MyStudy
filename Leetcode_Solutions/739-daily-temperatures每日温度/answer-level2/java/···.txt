### 解题思路
单调栈

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] result = new int[T.length] ;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);

        for (int i = 0; i < T.length; i++) {
            while (stack.peek() != -1 && T[stack.peek()] < T[i]) {
                result[stack.peek()] = (i-stack.pop());
            }
            stack.push(i);
        }

        while (stack.peek() != -1) {
            result[stack.pop()] = 0;
        }

        return result;
    }
}
```