### 解题思路
![屏幕快照 2020-02-15 17.53.06.png](https://pic.leetcode-cn.com/37ac6655b0e323228d312abb9d003a9c2779fea75e2b99facea8af7a4a30df80-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-15%2017.53.06.png)


### 代码

```java
class Solution {
    public int numWays(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        long first = 1;
        long sec = 1;
        for (long i = 2; i <= n; i++) {
            long val = (first + sec) % 1000000007;
            first = sec;
            sec = val;
        }
        return (int)sec;
    }
}
```