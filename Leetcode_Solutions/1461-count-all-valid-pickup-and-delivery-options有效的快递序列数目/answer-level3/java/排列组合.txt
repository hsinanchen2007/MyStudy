### 解题思路
数学问题，纸上画画就做出来了

### 代码

```java
class Solution {
    double sum = 6;
    public int countOrders(int n) {
        if (n == 1) return 1;
        for (int i = 2; i < n; i++) {
            sum = sum * (2 * i + 1 + ((2 * i + 1) * (2 * i)) / 2);
            sum = sum % (1000000007);
        }
        return (int)(sum % (1000000007));
    }
}
```