### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dit = {}
        for i in nums:
            if i not in dit:
                dit[i] = 1
            else:
                dit[i] += 1
        for i in nums:
            if dit[i] > len(nums)//2:
                return i 
        # count, majority = 1, nums[0]####投票算法，总是消去不同的元素，剩下的就是最多的
        # for num in nums[1:]:
        #     if count == 0:
        #         majority = num
        #     if num == majority:
        #         count += 1
        #     else:
        #         count -= 1
        # return majority


```