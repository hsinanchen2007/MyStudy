#### 思路
对`nums`排序保存在`nums_sort`中，然后遍历`nums_sort`，将值和索引保存在哈希字典`dic`中，格式为`{nums_sort值：索引}`。最后遍历原数组`nums`，将`nums[i]`替换为字典中的值。
#### 代码
```
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        dic = {}
        nums_sort = sorted(nums,reverse=True)
        for i in range(len(nums_sort)):
            if i == 0:
                dic[nums_sort[i]] = 'Gold Medal' # 前三名的值换成字符串，而非索引
            elif i == 1:
                dic[nums_sort[i]] = 'Silver Medal'
            elif i == 2:
                dic[nums_sort[i]] = 'Bronze Medal'
            else:
                dic[nums_sort[i]] = str(i+1) # 名次为索引值加1
        for j in range(len(nums)):
            nums[j] = dic[nums[j]] 
        return nums
```
#### 复杂度分析
- 时间复杂度:O(NlogN),对数组排序，然后遍历了一遍数组，遍历了一遍字典
- 空间复杂度：O(N),使用了`nums_sort`和`dic`