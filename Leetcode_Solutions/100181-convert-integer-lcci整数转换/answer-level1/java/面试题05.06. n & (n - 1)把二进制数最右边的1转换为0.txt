# 思路
本题等价于求两个数的二进制表示中有多少位不一样. 先对两个数进行异或运行(结果为n), 数值不同的位变为1, 相同的变为0. 再迭代计算```n & (n - 1)```, 每次计算都把n最右边的1转换为0, 不断迭代直到n等于0.

# 代码
```java
class Solution {
    public int convertInteger(int A, int B) {
        int count = 0;
        for (int n = A ^ B; n != 0; n &= n - 1) {
            count++;
        }
        return count;
    }
}
```