### 解题思路

这道题相当于将两个有序数列混合成一个新的有序数列，并且求其中位数
先新生成一个空List，nums3
每次比较两个数列的头部，将最小的元素放在nums末尾，直到原来的一个数列为空
然后将不为空的那个List直接接到nums3后面

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        nums3 = []

        while nums1 and nums2:
            if nums1[0] < nums2[0]:
                nums3.append(nums1.pop(0))
            else:
                nums3.append(nums2.pop(0))

        if not nums1 == []:
            nums3 += nums1
        elif not nums2 == []:
            nums3 += nums2

        # print(nums3)
        l = len(nums3)

        if l % 2 == 0:
            return (nums3[l // 2] + nums3[l // 2 - 1]) / 2
        else:
            return nums3[l // 2]
```