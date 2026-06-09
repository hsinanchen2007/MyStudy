### 解题思路
这种取整数各位数的方法要学会

### 代码

```java
class Solution {
    public int addDigits(int num) {
        while (num >= 10) {
            int tmp = num;
            int sum = 0;
            while (tmp > 0) {
                sum += tmp % 10;
                tmp = tmp / 10;
            }
            num = sum;
        }
        return num;
    }
}
```