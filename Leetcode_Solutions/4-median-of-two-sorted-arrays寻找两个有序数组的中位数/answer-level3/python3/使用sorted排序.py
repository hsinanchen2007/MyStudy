### 解题思路
先把两个列表合在一起，再用sorted进行排序，然后考虑两个列表合并后元素个数是偶或奇的情况

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = sorted(nums1 + nums2)

        if len(nums)%2 == 0:
            answer = (nums[int(len(nums)/2-1)] + nums[int(len(nums)/2)])/2

        else:
            answer = nums[int(len(nums)//2)]

        return answer
```