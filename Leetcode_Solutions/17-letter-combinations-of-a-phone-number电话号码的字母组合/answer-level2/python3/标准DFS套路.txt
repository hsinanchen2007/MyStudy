### 解题思路

标准DFS套路，写DFS时，先写退出条件，再处理后续分支。
注意dfs()前后的处理。

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # - sanity check
        if not digits:
            return []

        # - digit -> chars
        digit_dict = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        res = []

        # - dfs
        def dfs(index, s):
            # - return if reach the end
            if index == len(digits):
                res.append(s)
                return

            # - for every branches
            for c in digit_dict[digits[index]]:
                s += c
                dfs(index+1, s)
                s = s[:-1]
        
        # - from digits[0]
        dfs(0, '')

        return res

        
```