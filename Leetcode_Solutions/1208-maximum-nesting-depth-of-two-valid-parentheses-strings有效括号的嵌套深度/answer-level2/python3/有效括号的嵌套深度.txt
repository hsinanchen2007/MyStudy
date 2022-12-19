### 解题思路
做晚饭努力想打个卡，努力读题，放弃了，还是抄作业吧，明天清醒点再看仔细

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        d = 0
        for c in seq:
            if c == '(':
                d += 1
                ans.append(d % 2)
            if c == ')':
                ans.append(d % 2)
                d -= 1
        return ans

# 作者：LeetCode-Solution

```