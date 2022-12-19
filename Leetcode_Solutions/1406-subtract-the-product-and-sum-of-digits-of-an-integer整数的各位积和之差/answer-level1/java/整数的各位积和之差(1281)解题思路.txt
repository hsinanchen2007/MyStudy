### 解题思路
因为在1到10000之间，所以一直取余数（每个位数的数字），将余数累加和累乘，计算差值即可 

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int add = 0;
        int mul = 1;
        while(n > 0)
        {
            int remainder = n%10;
            add += remainder;
            mul *= remainder;
            n = n/10;
        }
        return (mul - add);
    }
}
```