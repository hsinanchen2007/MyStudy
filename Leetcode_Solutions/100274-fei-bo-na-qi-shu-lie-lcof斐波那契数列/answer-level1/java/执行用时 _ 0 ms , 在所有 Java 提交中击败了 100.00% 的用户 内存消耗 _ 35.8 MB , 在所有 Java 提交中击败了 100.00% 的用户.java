### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fib(int n) {
        if (n <= 1)
            return n;
        long fibOne = 0;
        long fibTow = 1;
        long res = 0;
        for (int i = 2; i <= n; i++) {
            res = (fibOne + fibTow) % 1000000007;
            fibOne = fibTow;
            fibTow = res;
        }
        return (int)res;
    }
}
```