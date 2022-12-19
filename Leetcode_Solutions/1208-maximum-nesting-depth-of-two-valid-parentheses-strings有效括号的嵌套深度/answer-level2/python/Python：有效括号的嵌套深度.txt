### 解题思路
只要连续两个((或))分在不同组就行了

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans=[0]
        for i in range(1,len(seq)):
            ans.append(1-ans[i-1]) if seq[i]==seq[i-1] else ans.append(ans[i-1])
        return ans
```