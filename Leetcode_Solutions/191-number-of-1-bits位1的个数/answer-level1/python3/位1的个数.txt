### 解题思路
思路：将`n`与1按位与，结果即为`n`的最后一位的二进制位，再将`n>>1`；继续循环从而计算出`n`二进制中的所有1个数；

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            m = n&1
            if m == 1:
                count+=1
            n >>= 1
        return count

```