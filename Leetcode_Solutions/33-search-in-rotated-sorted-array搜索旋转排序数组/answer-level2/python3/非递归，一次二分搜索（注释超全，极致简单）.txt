![image.png](https://pic.leetcode-cn.com/069ff20e5ed47239c85381a8d3de55ec275c9d4c431d2d361ce0319d868c635f-image.png)

```python
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        '''
        nums 可以划分为如下：
        [a,b]|[c,d]
        其中|是旋转点
        左边永远大于右边
        '''
        if not nums:
            return -1
        left = 0  # 记下数组左坐标
        # 后面需要利用切片重新赋值nums,每次循环都相当于一个新数组，省去利用下标的复杂
        is_sort = False  # 
        is_low = False  # 目标数在旋转数组的右小区间
        if nums[-1] > nums[0]:  # 数组有序的判断标准：如果数组尾大于数组头，数组就是有序的，直接二分即可
            is_sort = True
        
        # 将旋转数组二分，通过while将target限定在一有序子数组里
        # 数组只有一个元素时也是有序的
        while not is_sort and len(nums) > 1:
            if target < nums[0]:  # 如果目标值小于数组头，说明target在旋转数组的小区间
                is_low = True
            mid = len(nums)//2
            if nums[mid] == target:
                return left+mid
            if nums[mid] > nums[0]:
                # mid在a..b之间，此时nums为：
                # [a,mid,b]|[c,d]
                # mid左边已经有序
                # mid右边在mid=b时有序，否则仍是旋转数组
                if nums[mid] > target and not is_low:
                    # nums[mid]>target判断，确保a<=target<mid或者c<=target<=d
                    # is_low确认a<=target<mid，可以直接二分查找
                    # 新数组为有序数组，为：
                    # [a,mid)
                    is_sort = True
                    nums = nums[:mid]
                else:
                    nums = nums[mid+1:]
                    left = left + mid +1 # 记录新数组头在原数组的下标
            else: 
                # mid在c..d之间，此时nums为：
                # [a,b]|[c,mid,d]
                # mid右边已经有序
                # mid左边在mid=c时有序，否则仍是旋转数组
                if nums[mid] < target and is_low:
                    # nums[mid]<target判断，确保a<=target<=b或者mid<target<=d
                    # is_low 确认mid<target<=d
                    # 此时可以直接二分，新nums是有序数组，为：
                    # (mid,d]
                    nums = nums[mid+1:]
                    left = left + mid +1
                    is_sort=True
                else:
                    # [a,b]|[c,mid) 极可能是旋转数组
                    nums = nums[:mid]
            if nums and nums[-1] > nums[0]:  # 判断新数组是否有序
                is_sort = True 

        # 数组已经有序，直接二分
        while nums and nums[0] <= nums[-1]:
            mid = len(nums)//2
            if nums[mid] == target:
                return left + mid
            elif nums[mid] > target:
                nums = nums[:mid]
            else:
                nums = nums[mid+1:]
                left = left + mid+1

        return -1


if __name__ == "__main__":
    nums = [2,3,4,5,6,7,8,9,1]
    target = 9
    s = Solution()
    assert s.search(nums, target) == 7
    nums = [1,3,5]
    target = 5
    assert s.search(nums, target) == 2

```
