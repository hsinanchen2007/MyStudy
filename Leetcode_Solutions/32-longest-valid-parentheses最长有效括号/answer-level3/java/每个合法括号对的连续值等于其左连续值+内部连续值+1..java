### 解题思路
每一对成功配对的括号左边的连续()数称为该括号的左连续值，（）内部的连续()数称为内部连续值。
因此每一对括号的连续值= 左连续值 + 内部连续值 + 1  ；
遇到 ( 时，将当前的连续值压栈，作为(的左连续值，遇到)时，将之前的(的左连续值出栈 加上当前连续值[其实就是该()的内部连续值]，再+1；

### 代码

```java
class Solution {
    public int longestValidParentheses(String s) {
       int longestPairCount = 0;
        int curPairCount = 0;
        int curLeftCount = 0;
        int[] leftStack = new int[s.length()];

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                leftStack[curLeftCount] = curPairCount;
                curPairCount = 0;
                curLeftCount++;
                continue;
            }
            
            if (ch != ')') {
                continue;
            }

            // 右括号或其他字符
            if (curLeftCount > 0) {
                // 成功配对
                curPairCount = curPairCount + leftStack[curLeftCount - 1] + 1; // 当前连续 = (的左连续 + 1；
                curLeftCount--;

                // 非法),触发统计
                if (curPairCount > longestPairCount) {
                    longestPairCount = curPairCount;
                }
            } else {
                curPairCount = 0;
            }
        }

        // 遍历最后再触发一次比对
        if (curPairCount > longestPairCount) {
            longestPairCount = curPairCount;
        }

        return longestPairCount * 2;
    }
}
```