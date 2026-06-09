``` Python
class Solution:
    def __init__(self):
        self.kv = {
            '2': list('abc'),
            '3': list('def'),
            '4': list('ghi'),
            '5': list('jkl'),
            '6': list('mno'),
            '7': list('pqrs'),
            '8': list('tuv'),
            '9': list('wxyz'),
        }
        self.merge_dp = {}

    def merge(self, strlist1, strlist2):
        result = []
        for s in strlist1:
            for s2 in strlist2:
                result.append(s+s2)
        return result
        

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        if digits in self.kv:
            return self.kv[digits]
        digits_len = len(digits)
        self.kv[digits] = self.merge(self.letterCombinations(digits[0:digits_len//2]),
                            self.letterCombinations(digits[digits_len//2:]))
        return self.kv[digits]
```
