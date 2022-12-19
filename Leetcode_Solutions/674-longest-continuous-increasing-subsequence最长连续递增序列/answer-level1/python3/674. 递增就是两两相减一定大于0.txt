### 解题思路
1. 切记：list为空，返回0
2. 两两计算差值。
3. 判断差值是不是大于0。
4. 如果大于0，当前长度加1.
5. 如果小于0，当前长度置0.
6. 取上一个max_length和当前length最大的作为最大值。
7. 因为计数过程中，一直记录的是差值的个数，因此返回的时候记得+1.

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        d_value = []
        for idx in range(1, len(nums)):
            d_value.append(nums[idx]-nums[idx-1])
        
        max_length = 0
        current_length = 0

        for item in d_value:
            if item > 0:
                current_length += 1
                
            else:
                current_length = 0
            max_length = max(max_length, current_length)
        
        return max_length+1
```