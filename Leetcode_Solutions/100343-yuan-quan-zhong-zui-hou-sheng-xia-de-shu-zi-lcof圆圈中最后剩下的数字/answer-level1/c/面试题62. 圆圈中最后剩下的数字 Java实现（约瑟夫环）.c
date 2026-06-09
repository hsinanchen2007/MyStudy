### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int a1 = 0;
        int a2 = 0;
        for (int i = 2; i <= n; i++) {
            a2 = (m + a1) % i;
            a1 = a2;
        }
        return a2;
    }
}
```