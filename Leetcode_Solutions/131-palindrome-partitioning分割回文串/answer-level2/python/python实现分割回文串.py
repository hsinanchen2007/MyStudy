### 解题思路


### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        self.res = []
        self.n = len(s)
        if self.n == 0:
            return []
        temp = []
        self.backtrack(s, 0, temp)
        return self.res

    def backtrack(self, s, start, temp):
        if start >= self.n:
            self.res.append(temp.copy())
            return 
        for i in range(start, self.n):
            if self.check(s, start, i):
                temp += [s[start:i+1]]
                self.backtrack(s, i+1, temp)
                temp.pop()

    def check(self, s, i, j):
        if i >= j:
            return True
        if s[i] == s[j]:
            i += 1
            j -= 1
            return self.check(s, i, j)
        else:
            return False

```