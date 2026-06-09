### 解题思路
思路完全初学者水平，时间复杂度击败了12.34%，空间复杂度击败了5.06%。。
感觉这题用python写好容易。。。
记录一下，再接再厉！

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if nums1 == nums2 == None:
            return None
        if nums1 == None:
            l1 = len(nums2)
            if l1 % 2 == 0:
                return (nums2[int((l1)/2)] + nums2[int((l1)/2) -1] ) // 2.0
            else:
                return nums2[int(l1/2)]
        elif nums2 == None:
            l2 = len(nums1)
            if l2 % 2 == 0:
                return (nums1[int(l2/2)] + nums1[int(l1/2)] ) //2.0
        else:
            nums3 = sorted(nums1 + nums2)
            l3 = len(nums3)
            if l3 % 2 ==0 :
                return (nums3[int((l3)/2)] + nums3[int((l3)/2) -1]) / 2.0
            else:
                return nums3[int((l3)/2)]
```