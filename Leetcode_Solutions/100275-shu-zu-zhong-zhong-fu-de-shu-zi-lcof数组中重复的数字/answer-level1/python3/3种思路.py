### 解题思路
1.一开始想到的pop超时了
2.通过dict的特性
3.题目中有说所有数字小于n

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # i = 0
        # while(i < len(nums)):
        #     a = nums.pop(i)
        #     if a in nums:
        #         return a
        #     a += 1
        # 超时了
        # 
        # 解法一 
        # dct = {}
        # for num in nums:
        #     if num not in dct:
        #         dct[num] = 1
        #     else:
        #         return num
        
        lst = [0] * len(nums)
        for i in nums:
            if lst[i] == 0:
                lst[i] = 1
            else:
                return i
```