### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0]*(len(seq))
        sta = []
        flag = 0
        for i in range(len(seq)):
            if seq[i]=='(':sta.append(i)
            else:
                ans[sta.pop(0)]=flag%2
                ans[i] = flag%2
                flag += 1
        return ans


```