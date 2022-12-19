### 解题思路
1.寻找旋转点之后，再进行二分查找，查找旋转点的时间复杂度O(N),二分查找的时间复杂度O(logn)
2.考虑到二分查找其实没有必要追求都是有序数组，其本质应该是不断缩减数组长度，所以在可以明确那半部分可以舍弃时，就可以应用二分查找

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 直接进行二分查找
        lens = len(nums)
        if lens == 0:
            return -1
        a = 0
        b = lens-1
        while b>=a:
            mid = (a+b)//2
            if nums[mid] == target:
                return mid
            #与最左端比较，判断那半有序
                #右半有序
            if nums[a] > nums[mid]:
                if nums[mid]< target <= nums[b]:
                    a = mid+1
                else:
                    b = mid-1
                #左半有序
            else:
                if nums[mid] > target >= nums[a]:
                    b = mid-1
                else:
                    a = mid+1
        return -1

        # 找到旋转的分界点，再进行排序,但是可能时间复杂度为O(n+logn)
        """
        lens = len(nums)
        if lens<1:
            return -1
        j = 0
        for i in range(lens):
            if nums[i] >= nums[j]:
                j = i
            else:
                break
        if nums[0] <= target <= nums[j]:
            a = 0
            b = j
        elif nums[i] <= target <=nums[lens-1]:
            a = i
            b = lens-1
        else:
            return -1
        while b>=a:
            mid = (a+b)//2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                a = mid+1
            else:
                b = mid-1
        return -1
        """
```