不用加减乘除做加法的方法是使用按位异或和按位与运算。计算`a + b`等价于计算`(a ^ b) + ((a & b) << 1)`，其中`((a & b) << 1)`表示进位。因此令`a`等于`(a & b) << 1`，令`b`等于`a ^ b`，直到`a`变成0，然后返回`b`。
```
class Solution {
    public int add(int a, int b) {
        while (a != 0) {
            int temp = a ^ b;
            a = (a & b) << 1;
            b = temp;
        }
        return b;
    }
}
```
