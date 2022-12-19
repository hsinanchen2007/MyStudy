```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dig2let = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        res = [''] if digits else []
        for d in digits:
            res = [r + l for r in res for l in dig2let[d]]
        return res
```
