### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        now = -1
        ans = 0
        if height == []: return 0
        for i in range(len(height)):
            if height[i]>=now:
                if i+1 == len(height):break
                now = min(height[i], max(height[i+1:]))
                continue
            if now < 0:continue
            ans = ans + now - height[i]
            # print(i, now, ans)
        return ans


```