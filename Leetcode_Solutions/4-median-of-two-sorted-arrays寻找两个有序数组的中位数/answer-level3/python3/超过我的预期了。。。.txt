### 解题思路
我的思路比较简单吧，既然两个数组已经给定了先后顺序，那么我们就可以将这两个数组进行合并，合并成一个有序数组（由小到大），那么中位数就比较好求了。对于这道题而言，可以再优化一下，不一定需要合并完成，只需要合并的大数组的lenth超过nums1和nums2的lenth之和的一半就行。

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        l = l1 + l2
        nums3 = []
        k = 0
        m = 0
        for i in range((l+2)//2):
            if k < l1 and m <l2:
                if nums1[k] <= nums2[m]:
                    nums3.append(nums1[k])
                    k += 1
                else:
                    nums3.append(nums2[m])
                    m += 1
            else:
                if k >= l1:
                    nums3.append(nums2[m])
                    m += 1
                else:
                    nums3.append(nums1[k])
                    k += 1
        if l%2 == 1:
            return nums3[-1]
        else:
            return (nums3[-1]+nums3[-2])/2
```