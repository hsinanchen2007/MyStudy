### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n) {
        if (1 >= n)
            return 1;
        if (2 == n)
            return 2;

        int n1 = 1;
        int n2 = 2;
        int x = 3;
        for (int i=2; i<n; ++i) {
            x = (n1+n2)%1000000007;
            n1 = n2;
            n2 = x;
        }
        return x;
    }
}
```