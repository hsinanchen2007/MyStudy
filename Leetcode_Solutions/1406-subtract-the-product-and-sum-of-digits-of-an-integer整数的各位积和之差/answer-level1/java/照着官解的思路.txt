### 解题思路
通过n % 10 取余的方式,获取个位.再 n/10 使十位变成个位.循环

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int x = 1;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            x *= digit;
            sum += digit;
        }
        return x - sum;
    }
}
```