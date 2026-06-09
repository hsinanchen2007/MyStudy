### 解题思路
是不是我误会题目了啊，没看懂这道题的目的是什么。。

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(len(nums2)):
            nums1[-i-1] = nums2[i]
        nums1.sort()
```