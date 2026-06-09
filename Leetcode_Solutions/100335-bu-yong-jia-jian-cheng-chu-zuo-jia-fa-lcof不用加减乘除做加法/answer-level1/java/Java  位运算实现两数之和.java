### 解题思路
a ^ b ：表示a+b忽略进位的数值
(a & b) << 1 ：表示a+b的进位

### 代码

```java
class Solution {
    public int add(int a, int b) {
        while (b != 0) {
            int val = a ^ b; // val存储两数相加之后不进位的数值
            int k = (a & b) << 1; // k表示是否有进位
            a = val;
            b = k;
        }
        return a;
    }
}
```