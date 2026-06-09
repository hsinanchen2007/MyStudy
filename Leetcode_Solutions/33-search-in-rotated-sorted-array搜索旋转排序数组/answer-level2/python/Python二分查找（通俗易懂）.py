### 解题思路
因为题目要求控制在log(n)，加之是在一个几乎有序的数组中查找目标值，所以必然是用二分查找法。
关键点：
    0.特殊情况判断：空数组，返回-1
    1.将目标区间三等分，0：mid-1，mid，mid+1：len-1，若target = mid值，直接输出
    2.因为原数组存在一次旋转，且无重复元素，所以可根据mid值与left的大小，判断旋转点的位置（mid>left时，左侧单调，反之及mid<left则mid<right，右侧单调）
    3.针对旋转点在左右区间两种情形，分别判断：当target位于单调区间范围内时，向该侧收缩，否则一定向另一侧收缩。
    4.再额外判断下执行循环结束时的left取值是否等于target


![image.png](https://pic.leetcode-cn.com/4fc98a3d864344718fa228e1db2534da0cb4cc82691e3cbb0c0fcb6d23b37b19-image.png)


### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1
        left, right = 0, len(nums)-1
        while left < right:
            mid = left + (right - left)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] > nums[left]:
                if target == nums[left]:
                    return left
                elif nums[mid] > target > nums[left]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if target == nums[right]:
                    return right
                elif nums[mid] < target < nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
           
        if nums[left] == target:
            return left
        return -1
```