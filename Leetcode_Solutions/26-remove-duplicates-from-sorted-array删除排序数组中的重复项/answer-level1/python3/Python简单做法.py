### 解题思路
要注意题目中要求的是原地删除重复出现的元素，因此，set()就无法使用了，而且已经是排序的数组，就不用再考虑排序的问题了。
如果从正面考虑对nums进行去重的话，会非常麻烦，所以不如从后面进行操作，并且去掉重复元素。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for i in range(len(nums)-1,0,-1):
            if nums[i]==nums[i-1]:
                nums.pop(i)
        return len(nums)
```