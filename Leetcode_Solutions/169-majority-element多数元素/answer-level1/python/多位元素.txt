### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # dictData = {}
        # for num in nums:
        #     dictData[num] = dictData.get(num, 0) + 1
        #     if dictData[num] > len(nums)//2:
        #         return num

        # nums.sort()
        # return nums[len(nums)//2]

        count = 0
        candidate = float("inf") #初始时，候选人不存在
        for num in nums:
            if count == 0:#换新候选人
                candidate = num
            count += (1 if num==candidate else -1) #和自己一样，投正票，不一样投负票

        return candidate #多位元素的候选人一定会胜利
```