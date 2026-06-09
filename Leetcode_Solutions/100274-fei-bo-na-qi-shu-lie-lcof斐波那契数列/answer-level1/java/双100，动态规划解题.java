### 解题思路
![屏幕快照 2020-02-14 14.57.59.png](https://pic.leetcode-cn.com/1c31174e5ea110538b2331a2dc1ccc2b636165687ab636e157811328b7598e0a-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-14%2014.57.59.png)


### 代码

```java
class Solution {
    // 动态规划思路解决斐波那契
    public int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        long first = 0;
        long sec = 1;
        for (int i = 2; i <= n; i++) {
            long nval = first + sec;
            first = sec;
            sec = nval % 1000000007;
        }
        return (int)sec;
    }
}
```