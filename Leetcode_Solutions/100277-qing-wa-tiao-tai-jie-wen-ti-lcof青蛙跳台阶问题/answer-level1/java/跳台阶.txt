### 解题思路
和斐波纳挈数列求解一模一样。。。。

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            return 1;
        }
        int[] drop = new int[n + 1];
        drop[0] = 1;
        drop[1] = 1;
        for(int i = 2;i <= n;i ++) {
            drop[i] = (drop[i - 1] + drop[i - 2]) % 1000000007;
        }
        return drop[n];
    }
}
```