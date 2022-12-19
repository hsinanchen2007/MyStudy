### 解题思路

- 将x，y按位异或得到i，将问题转化为求i的二进制位中1的个数count
- 当i不为0时，将i与1按位与，判断二进制末尾是不是1，是，count++
- 将i右位移一位
- 重复第二，第三步，直到第二步条件不满足，，即i==0时终止统计， 即可得到i的二进制位中1的个数，问题得解

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int i = x ^ y;
        int count = 0;
        while (i != 0) {
            if ((i & 1) == 1) {
                count++;
            }
            i = i >> 1;
        }
        return count;
    }
}
```