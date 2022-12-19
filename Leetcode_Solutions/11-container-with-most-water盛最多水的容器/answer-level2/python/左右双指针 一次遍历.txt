### 解题思路
左右双指针 一次遍历
高度由小的决定

### 代码

```python
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0;
        right = len(height) - 1;
        width = right - left;
        max_area = width * min(height[left], height[right]);

        while (left != right):
            if height[left] > height[right]:
                right -= 1;
            else:
                left += 1;
            cur = (right-left) * min(height[left], height[right])
            max_area = max(cur, max_area)
        return max_area
```

# Java
```
class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int max_area = (right - left) * Math.min(height[left], height[right]);
        while(left != right) {
            if (height[left] < height[right]) {
                left += 1;
                int cur = (right - left) * Math.min(height[left], height[right]);
                max_area = Math.max(max_area, cur);
            }
            else {
                right -= 1;
                int cur = (right - left) *  Math.min(height[left], height[right]);
                max_area = Math.max(max_area, cur);
            }
        }
        return max_area;
    }
        
}
```
