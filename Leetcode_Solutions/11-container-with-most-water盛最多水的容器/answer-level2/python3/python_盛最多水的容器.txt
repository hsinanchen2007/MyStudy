### 解题思路
方法一：双指针法
左右逼近，桶壁高的有可能比之前容积大

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j, area = 0, len(height) - 1, 0
        while i < j:

            if height[i] < height[j]:
                area = max(area, height[i] * (j - i))
                i += 1
            else:
                area = max(area, height[j] * (j - i))
                j -= 1
        return area
```

### 解题思路
方法二：暴力计算
Python超时

### 代码
```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        area=0
        for i in range(len(height)-1):
            for j in range(i+1,len(height)):
                area=max(area,(j-i)*min(height[i],height[j]))
        return area
```