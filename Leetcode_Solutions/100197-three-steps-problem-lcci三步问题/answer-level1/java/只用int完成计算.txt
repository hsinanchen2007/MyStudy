### 解题思路
根据递推式，每次取值的时候对前面较大的两个数取模，最后整体取模可防止超过2倍1000000007，保证不超过int最大值（2147483647）

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        if (n <= 2) return n;
        int a = 1, b = 1, c = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = (a + (b + c) % 1000000007) % 1000000007;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
}
```