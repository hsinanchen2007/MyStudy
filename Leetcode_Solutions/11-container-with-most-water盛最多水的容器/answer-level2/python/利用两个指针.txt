p、q为两个指针，分别指向最开始的数字和最末位的数字

### 代码

```python
class solution:
    def mostwater(self, height: List[int]) -> int:
        p = 0
        q = len(height) - 1
        max_area = 0
        while p != q:
            short_board = min(height[p], height[q])
            bottom = q - p
            max_area = max(max_area, short_board * bottom)
            if height[p] < height[q]:
                p += 1
            else:q -= 1
        return max_area
```