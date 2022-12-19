### 解题思路
与前一个相同就是1，不同就是0
有连续的（（
或者连续的））就变换值

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0]
        for i in range(1, len(seq)):
            if seq[i] == seq[i-1]:
                ans.append(1 - ans[i-1])
            else:
                ans.append(ans[i-1])
        return ans
```