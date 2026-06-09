### 解题思路
根据官方题解使用了`last = {c:i for i, c in enumerate(S)}`来获取每个字符最后一次出现的位置

比起每次从句末往前寻找字符出现位置的效率高，执行用时从 1072ms 提升到 64ms

### 代码

```python3
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last = {c:i for i, c in enumerate(S)}
        k, ans = 0, []
        for idx, c in enumerate(S):
            k = max(last[c], k)
            if k == idx:
                ans.append(k - sum(ans) + 1)
        return ans
```