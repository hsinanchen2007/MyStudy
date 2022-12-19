### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n == 0)
            return 1;
        if(n <= 2)
            return n;
        long fibOne = 1;
        long fibTow = 2;
        long res = 0;
        for (int i = 3; i <= n; i++) {
            res = (fibOne + fibTow) % 1000000007;
            fibOne = fibTow;
            fibTow = res;
        }
        return (int) res;
    }
}
```