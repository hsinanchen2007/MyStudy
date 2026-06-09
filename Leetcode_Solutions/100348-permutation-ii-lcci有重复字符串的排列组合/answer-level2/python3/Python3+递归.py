### 解题思路
递归，首先确定排列中的首位，然后求剩下的字符所能构成的所有排列，把它们一一接到首位后面即可。
注意在遍历所有可能的首位时，不要有重复。

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        if len(S) == 0:
            return ['']
        ans = [S[0] + t for t in self.permutation(S[1:])]
        for i in range(1, len(S)):
            if S[i] not in S[:i]:
                t = S[1:i]+S[0]+S[i+1:]
                ans += [S[i] + k for k in self.permutation(t)]
        return ans
```