```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 对列表排序，代价是一倍原列表的存储空间
        asc_nums = sorted(nums)
        # 初始化首尾指针
        pos1 = 0
        pos2 = len(asc_nums) - 1
        stop = False
        exist = True
        # 当没有找到两个加数，并且仍可能存在解时，首尾指针分别向后、向前移动
        while not stop and exist:
            while asc_nums[pos2] > target - asc_nums[pos1] and pos2 > pos1:
                pos2 -= 1
            while asc_nums[pos1] < target - asc_nums[pos2] and pos1 < pos2:
                pos1 += 1
            # 首尾指针相等，不存在解，退出循环
            if pos1 == pos2:
                exist = False
            # 找到解，退出循环
            if asc_nums[pos1] + asc_nums[pos2] == target:
                stop = True
        if exist == False:
            return None
        else:
            # 针对两个加数相等的情况，第二个加数的索引从表尾向前搜索
            pos1 = nums.index(asc_nums[pos1])
            nums.reverse()
            pos2 = len(nums) - 1 - nums.index(asc_nums[pos2])
            return [pos1, pos2]
```
