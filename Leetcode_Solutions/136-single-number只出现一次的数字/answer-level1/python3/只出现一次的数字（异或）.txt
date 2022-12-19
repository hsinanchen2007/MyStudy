### 解题思路
n个1异或：如果n为奇数，则结果为1；如果n为偶数，则结果为0；

假设只出现一次的数字为m；

将nums中的所有整数进行异或，对于二进制形式的第k位：如果m的二进制第k位为0，则最终在该位上共有偶数的1进行异或，结果为0；如果m的二进制第k位为1，则最终在该位上共有奇数的1进行异或，结果为1；

因此将所有nums中的整数进行异或，最终的结果即为m；


### 代码

```python3
class Solution:
    """
    异或：nums[0] ^ nums[1] ^ nums[2] ^ ... ^ nums[n-1]
    """
    def singleNumber(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 1:
            return nums[0]
        
        res = 0
        for i in range(length):
            res ^= nums[i]
        
        return res

```