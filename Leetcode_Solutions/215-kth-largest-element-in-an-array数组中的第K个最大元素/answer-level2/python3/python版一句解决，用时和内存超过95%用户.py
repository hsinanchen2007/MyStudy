### 解题思路

![image.png](https://pic.leetcode-cn.com/bac67baf258f8884c46c8b324a36ade7f4c6eeed04855e8095d3d3465beca4fc-image.png)


### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sorted(nums)[len(nums)-k]
```