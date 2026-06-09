### 解题思路
使用BigDecimal代替+ - * /

### 代码

```java
class Solution {
    public int getSum(int a, int b) {
        BigDecimal a1 = new BigDecimal(a);
        BigDecimal b1 = new BigDecimal(b);
        return a1.add(b1).intValue();
    }
}
```