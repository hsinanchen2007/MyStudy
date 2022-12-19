### 解题思路
看多了官方思路，这一次在自己的正确思路下，写出的代码与官方基本上雷同，真是吓人。另外，这种方法叫双指针法，学到了。

### 代码

```python3
class Solution:
    def maxArea(self, height) -> int:
        i,j = 0,len(height)-1
        area = 0
        while i<j:
            area = max((j-i)*min(height[i],height[j]),area)
            if height[i]>height[j]:
                j-=1
            else:
                i+=1
        return area
```