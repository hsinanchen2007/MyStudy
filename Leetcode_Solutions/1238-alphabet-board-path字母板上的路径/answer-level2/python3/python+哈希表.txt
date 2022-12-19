### 解题思路
分情况讨论

### 代码

```python3
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        d = {}
        for i in range(97,123):
            d[chr(i)] = ((i-97)//5,(i-97)%5)
        start = (0,0)
        ans = ''
        for i in range(len(target)):
            cur = d[target[i]]
            if cur == (5,0):
                if cur[1] >= start[1]:
                    ans += (cur[1] - start[1]) * 'R'
                else:
                    ans += (start[1] - cur[1]) * 'L'
                if cur[0] >= start[0]:
                    ans += (cur[0] - start[0]) * 'D'
                else:
                    ans += (start[0] - cur[0]) * 'U'
            else:
                if cur[0] >= start[0]:
                    ans += (cur[0] - start[0]) * 'D'
                else:
                    ans += (start[0] - cur[0]) * 'U'
                if cur[1] >= start[1]:
                    ans += (cur[1] - start[1]) * 'R'
                else:
                    ans += (start[1] - cur[1]) * 'L'
            ans += '!'
            start = cur
        return ans
```