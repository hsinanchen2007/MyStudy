### 解题思路
看到好题解都是**反向遍历**，感觉面试时候很**难想到**，且相比正向遍历的**耗时更多**。于是提供我写的正向遍历的思路供大家参考：
1. 将初始位置的索引`0`添加到栈中；
2. 正向遍历数组 `T[]`；
3. 查看栈里面的索引所代表的那天的温度是否小于当前温度，如果小于，则记录它们之前索引的差值；
4. 将当前天的索引入栈。

### 代码

```java
class Solution {
     
    // #1 正向遍历
    public int[] dailyTemperatures(int[] T) {
        if (T == null || T.length == 0) {
            return new int[0];
        }

        int[] ans = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        stack.push(0);

        for (int i = 1; i < T.length; i++) {
            int cur = T[i];

            while (!stack.isEmpty()) {
                int lastIndex = stack.peek();
                if (T[lastIndex] < cur) {
                    ans[lastIndex] = i - lastIndex;
                    stack.pop();
                } else {
                    break;
                }
            }

            stack.push(i);
        }

        return ans;
    }
    
    // #2 反向遍历
    // public int[] dailyTemperatures(int[] T) {
    //     if (T == null || T.length == 0) {
    //         return new int[0];
    //     }

    //     int[] ans = new int[T.length];
    //     Stack<Integer> stack = new Stack<>();

    //     for (int i = T.length - 1; i >= 0; i--) {
    //         while (!stack.isEmpty() && T[i] >= T[stack.peek()]) {
    //             stack.pop();
    //         }
    //         ans[i] = stack.isEmpty() ? 0 : stack.peek() - i;
    //         stack.push(i);
    //     }

    //     return ans;
    // }
}
```