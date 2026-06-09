### 解题思路
一个数后面有多少个零是由这个数里面有几个5的因子决定的

因为 2 * 5 = 10 而 2 的数量远多于5

有的数字有两个5的因子，比如说25 ，这个时候就要再除一次5把这些数字找出来

### 代码

```java
class Solution {
    public int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
}
```