### 解题思路
看代码最清楚

### 代码

```python3
class Solution:
    def __init__(self):
        self.res = []
        self.d = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
             '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        self.track = ''
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        n = len(digits)
        if n == 1:
            return [x for x in self.d[digits]]
        self.backtrack(digits, self.track,0)
        return self.res
    def backtrack(self,digits,track,index):

        if len(track) == len(digits):
            self.res.append(track)
            return
        else:
            c = digits[index]
            s = self.d[c]
            for i in s:
                # if i in track:
                #     continue
                track = track+i
                self.backtrack(digits,track,index+1)
                track = track[:-1]
```