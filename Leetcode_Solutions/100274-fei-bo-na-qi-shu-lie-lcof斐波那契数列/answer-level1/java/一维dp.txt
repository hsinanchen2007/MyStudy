### 解题思路
此处撰写解题思路
这书的dp怎么这么喜欢一维，这么喜欢斐波那契。。。第二道了...
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
36.2 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        int dp[] = new int[n + 1];
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++){
            dp[i] = (dp[i - 1] + dp[ i - 2]) % 1000000007;
        }
        return dp[n];
    }
}
```