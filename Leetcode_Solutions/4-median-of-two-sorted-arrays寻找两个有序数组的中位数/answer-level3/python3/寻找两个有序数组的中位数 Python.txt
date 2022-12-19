# 思路
- 先简单地将两个有序数组合并和排序。

- 再顺便求出中位数并返回。


# 代码
```
class Solution:
    """
    辅助的排序函数。
    """
    def mergesort(self,nums1: List[int], nums2: List[int]) -> List[int]:

            # 直接创建一波长度合格的新数组。

            alist = [None] * (len(nums1) + len(nums2))

            #中心思想就是比较两个数组开头最小的项，谁更小谁放入新数组。

            i, j, k = 0, 0, 0
            while i < len(nums1) and j < len(nums2):
                if nums1[i] < nums2[j]:
                    alist[k] = nums1[i]
                    k = k + 1
                    i = i + 1
                else:
                    alist[k] = nums2[j]
                    k = k + 1
                    j = j + 1

            # 康康谁还没被放入新数组，以防有漏网之鱼。

            while i < len(nums1):
                alist[k] = nums1[i]
                k = k + 1
                i = i + 1
            while j < len(nums2):
                alist[k] = nums2[j]
                k = k + 1
                j = j + 1

            return alist

    """
    求中位数函数
    """
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        # 使用辅助排序函数得到合并而且有序的数组。

        alist = self.mergesort(nums1, nums2)

        # 因为已经有序，求中位数的过程变的枯燥乏味。

        if len(alist) % 2 == 0 :
            index1, index2 = len(alist)//2 - 1, len(alist)//2
            return (alist[index1] + alist[index2]) / 2
        else:
            index = len(alist) // 2
            return alist[index]
```
