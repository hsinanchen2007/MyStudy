### 解题思路
两种方法

### 代码

```python3
nums1 = [1, 2]
nums2 = [3, 4]


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):

        num=sorted(nums1+nums2)
        lens=len(num)
        return ((num[lens//2]+num[(lens-1)//2])/2)
answer = Solution()
r = answer.findMedianSortedArrays(nums1, nums2)
print(r)
```
```python3
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        L = len(nums1) + len(nums2)
        nums1.extend(nums2)
        nums = nums1

        nums = self.bubble_sort(nums)
        print(L%2)
        if L%2 == 0:
            medium = (nums[int(len(nums)/2-1)] + nums[int(len(nums)/2)])/2
        else:

            medium = nums[int((len(nums)+1)/2 - 1)]
        return medium

    def bubble_sort(self,nums):

        for i in range(len(nums) - 1):
            ex_flag = False  # 改进后的冒泡，设置一个交换标志位
            for j in range(len(nums) - i - 1):

                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    ex_flag = True
            if not ex_flag:
                return nums  # 这里代表计算机偷懒成功 (〃'▽'〃)

        return nums  # 这里代表计算机没有偷懒成功 o(╥﹏╥)o
```