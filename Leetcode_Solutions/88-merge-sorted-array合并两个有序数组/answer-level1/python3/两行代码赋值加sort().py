### 解题思路
看了题解中好多人也是用到了sort()函数
思路：
1. nums1中的后半部分赋值为nums2
2. 对新的nums1排序

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[m:] = nums2
        return nums1.sort()
```