### 解题思路
首先将数字压入栈，如果栈顶与输出序列相等，就直接pop()直到不等，然后在继续压入，最后判断栈是否为空。

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> A = new Stack<>();
        int index = 0;
        for (int i = 0; i < pushed.length; i++) {
            A.push(pushed[i]);

            while (!A.isEmpty() && index < popped.length && A.peek() == popped[index]) {
                A.pop();
                index++;
            }

        }

        return A.isEmpty();

    }
}
```