```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        res, l, r = 0, 0, len(height) - 1
        while l < r: res, l, r = (max(res,  height[l] * (r - l)), l + 1, r) if height[l] < height[r] else (max(res,  height[r] * (r - l)), l, r - 1)
        return res
```
- 双指针 O(N) 解法
- res：结果，l：容器左壁索引，r：容器右壁索引
- 如果 height[l] < height[r] 那么 l += 1 否则 r -= 1，说明：如果 height[0] < height[3] 那么(0, 1), (0, 2)对应的容器体积一定小于(0, 3)的，因为此时计算体积的时候高为 height(0)，容器的宽减少而高不增加，面积必然缩小