### 解题思路
我们可以通过统计每一位出现的次数是否是3的倍数来判断只出现一次的数字在该位是否为1，这样就可以得到出现先一次的数字在每一位上是0还是1，进而转化为这个数。

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        bit_num = [0] * 32
        for num in nums:
            bit = 0
            while num:
                if num & 1:
                    bit_num[bit] += 1
                bit += 1
                num = num >> 1
        res = 0
        for i in range(32):
            if bit_num[i] % 3:
                res |= 1 << i

        return res
```