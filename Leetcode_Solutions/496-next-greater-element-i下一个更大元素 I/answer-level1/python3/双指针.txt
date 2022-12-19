### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for i in nums1:
            index = nums2.index(i)
            while index < len(nums2):
                index += 1
                if index >= len(nums2):
                    break
                if nums2[index] > i:
                    res.append(nums2[index])
                    break
            if index == len(nums2) and nums2[-1] <= i:
                res.append(-1)

        return res
```