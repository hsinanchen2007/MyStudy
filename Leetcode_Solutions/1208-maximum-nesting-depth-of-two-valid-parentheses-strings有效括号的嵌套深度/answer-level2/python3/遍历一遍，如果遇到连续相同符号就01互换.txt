### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        x = 0
        temp = ')' + seq[:-1]
        ans = [temp[i]==seq[i] for i in range(len(seq))]
        for i in range(len(seq)):
            if ans[i]:
                x = 1 - x
            ans[i] = x
        return ans
```