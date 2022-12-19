### 解题思路
1. 首先二分搜索值是否在里面
2. 存在的话使先用二分法找左边第一次出现的位置（左边再将范围“一半一半”缩小时到最后一次时, l指针只会指向mid）
3. 再找最右边最后出现的位置（最后l指针会指向一个在最右位置插入该值仍能保证列表有序的位置）

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        pl, pr = -1, -1
        if self.bisch(nums, target):
            pl = self.b_left(nums, target)
            pr = self.b_right(nums, target) - 1
        return [pl, pr]

    def bisch(self, nums, target):
        l, u = 0, len(nums) - 1
        while l <= u:
            mid = (l + u) // 2
            if target == nums[mid]: 
                return True
            elif target < nums[mid]: 
                u = mid - 1
            else: 
                l = mid + 1
        return False

    def b_left(self, nums, target):
        """左边的坐标"""
        l, h = 0, len(nums)
        while l < h:
            mid = (l + h) // 2
            if nums[mid] < target:
                l = mid + 1  # 缩小进一半范围
            else: 
                h = mid
        return l

    def b_right(self, nums, target):
        """右边的坐标"""
        l, h = 0, len(nums)
        while l < h:
            mid = (l + h) // 2
            if nums[mid] > target:
                h = mid  # 缩小进一半范围
            else:
                l = mid + 1
        return l
```