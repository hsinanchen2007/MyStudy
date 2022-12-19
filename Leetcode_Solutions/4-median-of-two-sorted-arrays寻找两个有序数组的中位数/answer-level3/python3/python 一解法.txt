### 解题思路
由于数组事有序的，先归并排序，然后取中位数

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        index1 = 0
        index2 = 0
        combined = []
        length = len(nums1) + len(nums2)
        for i in range(length):
            if index1 == len(nums1):
                combined.extend(nums2[index2:])
                break
            elif index2 == len(nums2):
                combined.extend(nums1[index1:])
                break
            elif nums1[index1] >= nums2[index2]:
                combined.append(nums2[index2])
                index2 += 1
            else:
                combined.append(nums1[index1])
                index1 += 1
        print(combined)
        if length % 2 == 0:
            return (combined[length // 2 - 1] + combined[length // 2]) / 2
        else:
            return combined[length // 2]

```