### 解题思路
主要应用索引i的遍历，对负数进行处理，将其设置为len(nums)+1
同时对i索引值的元素进行判断 如果该值对应的索引位置上的数大于它，例如[6, 4, 0 ,-1, 1, 3]， 
当i==4，读到nums[4]==1, num[1 - 1] == 6时, 1 < 6 交换1和6的位置，对新值6进行进一步判断发现 nums[6 - 1] == 3 由于 6 > 3 则i = i + 1 进入下一索引值。

### 代码

```python
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1
        i = 0
        while i < len(nums):
            if nums[i] == i + 1:       # 判断某索引对应的数组元素是否为该索引值+1， 例如nums[0]是否为1, nums[4]是否为5
                i = i + 1
                continue
            if nums[i] <= 0 or nums[i] >= len(nums) + 1: # 对小于0的数组元素统一处理，将值设为len(nums) + 1对结果没影响
                nums[i] = len(nums) + 1
                i += 1
                continue
            if nums[nums[i] - 1] == nums[i]:   # 避免出现重复元素情况，例如[1,1,2,2,2,2,3,3,3,5,6,7] 当我们读到第二个1时，i == 1, nums[i] == 1, nums[nums[i]-1] == 1, 将第二个1改成len(nums) + 1
                nums[i] = len(nums) + 1
                continue
            if nums[nums[i] - 1] > nums[i]:    # 循环判断nums[nums[i] - 1] 和 nums[i]大小    例如判断 i = 5时  nums[5 - 1]与nums[5]的大小
                tmp = nums[nums[i] - 1]
                nums[nums[i] - 1] = nums[i]
                nums[i] = tmp
                continue
            i += 1
            
        res = 1
        print(nums)             #统计
        for i in range(len(nums)):
            if nums[i] != i + 1:
                res = i + 1
                break
            res += 1
        return res

```