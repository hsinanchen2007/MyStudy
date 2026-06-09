### 解题思路
加个cache，避免重复运算
![20200401-205858(WeLinkPC).png](https://pic.leetcode-cn.com/80532bf0f3e395ac9bdce5cb61484c101cab1181b1e2601c9a990d89efc3a905-20200401-205858\(WeLinkPC\).png)


### 代码

```java
class Solution {
    private long cache[];
    public int numWays(int n) {
        if (0 == n)
            return 1;
        cache = new long[n+2];
        return helper(n) % 1000000007;
    }

    private int helper(int n) {
        if (n <= 0){
            cache[0] = 0;
            return 0;
        }
        if (n == 1){
            cache[1] = 1;
            return 1;
        }
        if (n == 2) {
            cache[2] = 2;
            return 2;
        }
        if (0 == cache[n]) {
            long val = (helper(n-2) + helper(n-1))%1000000007;
            cache[n] = val;
            cache[n+1] = (cache[n] + cache[n-1])%1000000007;
        }
        return (int)cache[n];
    }
}
```