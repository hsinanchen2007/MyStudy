### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int climbStairs(int n) {
 if (n <= 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int dp0 = 1;
        int dp1 = 2;
        for (int i = 3; i <= n; i++) {
            int dpn = dp0 + dp1;

            dp0 = dp1;
            dp1 = dpn;
        }
        return dp1;
    }
}
```