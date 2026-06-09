### 解题思路
把每个值放在对应的下标的位置，除了首位的0以外，哪个位置上是0，哪个数字就缺失

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        if 0 not in nums:
            return 0
        tmp = [0] * (len(nums) + 1)  # 用零初始化一个长度为n+1的数组，用于存放每个值
        
        for num in nums: # 把每个数存到对应下标的位置
            tmp[num] = num
        
        for i in range(1,len(tmp)):
            if tmp[i] == 0:
                return i

        # return sum([i for i in range(len(nums)+1)])-sum(nums)  大佬的牛解法：利用差值来找缺失的那个数

```