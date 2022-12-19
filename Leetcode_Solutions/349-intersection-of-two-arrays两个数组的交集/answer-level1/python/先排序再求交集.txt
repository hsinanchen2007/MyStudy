### 解题思路
时间复杂度：O（nlogn）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)
        length = len(nums1) if len(nums1) < len(nums2) else len(nums2)
        out = []
        if length == len(nums1):
            for i in nums1:
                if i in nums2 and i not in out:
                    out.append(i)
        else:
            for i in nums2:
                if i in nums1 and i not in out:
                    out.append(i)
        return out

```