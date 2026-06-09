### 解题思路
1.暴力法：遍历所有”容器壁“
2.双指针：指针位于两端，为追求最大的体积，不断向内移动短板。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:

        # 双指针从两端开始,短板不断向中心移动以求得到体积提升
        
        lens = len(height)
        i = 0
        j = lens - 1
        ms = 0
        while j >= i:
            b = j-i
            if height[j] >= height[i]:
                s = height[i] *(j-i)
                i += 1
            else:
                s = height[j] *(j-i)
                j -= 1
            ms = s if s > ms else ms
        return ms
        
        # 暴力
        """
        lens = len(height)
        ms = 1
        for i in range(lens):
            for j in range(i, lens):
                if j-i >=1:
                    l = min(height[i], height[j])
                    s = l*(j-i)
                    ms = s if s>ms else ms
        return ms
        """
```