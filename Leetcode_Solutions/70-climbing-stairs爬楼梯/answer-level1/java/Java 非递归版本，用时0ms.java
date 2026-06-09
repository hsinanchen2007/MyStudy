### 解题思路
第n阶台阶的方案数 = 第n-1阶的方案数 + 第n-2阶的方案数， 这就是一个斐波那契数列。

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        int first = 0, second = 1, tmp;
        for(int i = 1; i <= n; i ++){
            tmp = second;
            second += first;
            first = tmp;
        }
        return second;
    }
}
```