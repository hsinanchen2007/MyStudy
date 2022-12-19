### 解题思路
python 一行解决。  
本来我是写了个冒泡排序的，提交通过后才发现大家都用 sort 函数。  

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[:m+n] = sorted(nums1[:m]+nums2[:n])
            
```