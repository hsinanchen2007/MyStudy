### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:

        ans = 0
        for i in range(1,len(height)-1):
            max_left = 0
            max_right = 0

            ###为什么要把第i个元素算在内呢？
            for j in range(0,i+1):
                if max_left < height[j]:
                    max_left = height[j]
            for k in range(i,len(height)):
                if max_right < height[k]:
                    max_right = height[k]
            ans += min(max_right,max_left)-height[i]
        return ans
            
            

```