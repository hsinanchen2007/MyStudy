### 解题思路
题目要求是将一个**有效括号串**拆成两个**有效括号串**，尽可能使得两个括号串的**嵌套深度**最小。

- **有效括号串**：左右括号数相等，右括号出现之前必须出现一个左括号
- **嵌套深度**：我理解的嵌套深度就是**连续**出现左括号（或者右括号）的**最大**次数。例如：
    - `((()))`，左括号最多**连续**出现了`3`次，所以嵌套深度是`3`
    - `(())()`，左括号最多**连续**出现了`2`次，所有嵌套深度是`2`

题目要求拆分的两个子括号串的**嵌套深度**尽可能小，而且两个拆分时**可以不连续**，那就很简单，将原括号串中的左右括号**轮流分配**给两个子串就行了，因为此时两个子括号串的**嵌套深度之差**至多为`1`，那么
$max(depth(A), depth(B))$肯定最小。

### 代码

```java

class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq == null) {
            return null;
        }
        int[] result = new int[seq.length()];
        // 作为轮流分配的标志 
        boolean flag = true;  
        for (int i = 0; i < seq.length(); i++) {
            char c = seq.charAt(i);
            if (c == '(') {
                if (flag) {
                    result[i] = 1;
                } else {
                    result[i] = 0;
                }
            } else {
                if (flag) {
                    result[i] = 0;
                } else {
                    result[i] = 1;
                }
            }
            flag = !flag;
        }
        return result;
    }
}
```