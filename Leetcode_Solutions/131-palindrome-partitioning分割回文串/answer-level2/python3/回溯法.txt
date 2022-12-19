### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []

        def check(start: int, end: int):
            reverse_s = list(s[start:end])
            reverse_s.reverse()
            tmp = "".join(reverse_s)

            if s[start:end] == tmp:
                return True
            else:
                return False

            pass

        def dfs(start: int, end: int, path: List[str]):
            if start == end:
                res.append(path)
                return
            for i in range(start, end):
                if check(start, i + 1) is True:
                    dfs(i + 1, end, path + [s[start:i + 1]])

            pass

        dfs(0, len(s), [])

        return res
```