### 解题思路
首先用二分查找的思路来找到divide_point, 然后对nums进行重新组装
然后就是对已经有序的nums进行二分查找了.
如果用我这种递归写法来做二分查找, 不要漏掉if left > right这个情况.

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 先二分查找看下是否正常
        len_nums = len(nums)
        if len_nums <= 0:
            return -1
        if len_nums == 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        if nums[-1] > nums[0]:  # 没有旋转
            return self.binary_search(nums, 0, len_nums-1, target)
        # 旋转了
        divide_point = self.find_divide_point(nums, 0, len_nums-1)
        nums = nums[divide_point:] + nums[:divide_point]
        index = self.binary_search(nums, 0, len_nums-1, target) 
        drag_length = len_nums - divide_point
        if index == -1:
            return -1
        if index < drag_length:  # 是被挪到前面的段
            return divide_point + index
        else:  # 是往后移动的段
            return index - drag_length
    
    def find_divide_point(self, nums, left, right):
        if right - left == 0:
            return -1
        if right - left == 1:
            return right
        mid = (left + right) // 2
        if nums[mid] > nums[mid + 1]:
            return mid + 1
        elif nums[left] > nums[mid]:
            return self.find_divide_point(nums, left, mid)
        else:
            return self.find_divide_point(nums, mid+1, right)
    
    def binary_search(self, nums, left, right, target):
        if left > right:
            return -1
        if left == right:
            if nums[left] == target:
                return left
            else:
                return -1
        mid = (left + right) // 2
        
        if target == nums[mid]:
            return mid
        elif target < nums[mid]:
            return self.binary_search(nums, left, mid - 1, target)
        else:
            return self.binary_search(nums, mid + 1, right, target)

```