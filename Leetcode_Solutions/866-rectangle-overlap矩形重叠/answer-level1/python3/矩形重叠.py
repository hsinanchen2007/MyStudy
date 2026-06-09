### 解题思路
相交的情况太冗余容易漏，考虑不相交的情况

### 代码

```python3
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # 考虑两矩形不相交的情况，当二矩形x的最大值都小于一矩形的最小值，或者二矩形最小值都大于一矩形的最大值时（说最大值最小值不严谨）
        if rec2[2]<=rec1[0] or rec1[2]<=rec2[0]:
            return False
        #y轴判断同理
        if rec1[1]>=rec2[3] or rec2[1]>=rec1[3]:
            return False
        else:
            return True
```