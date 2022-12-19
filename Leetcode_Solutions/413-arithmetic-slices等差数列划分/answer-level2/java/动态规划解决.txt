### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a2b40fcc544f2cf4645e734ac8c6635cb4af3bd2b80f49130d0fbd0017e2d70b-image.png)

使用动态规划解决，状态转移方程为
```java
if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
    dp[i] = dp[i - 1] + 1;
}
```
即如果当前位置元素i可以和前两个位置元素构成等差数列，那么以当前位置为结尾的等差数列的数量即为
以前一个元素为结尾的等差数列的数量 + 1
### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int[] dp = new int[A.length];
        int count = 0;
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            count = count + dp[i];
        }
        return count;
    }
}
```