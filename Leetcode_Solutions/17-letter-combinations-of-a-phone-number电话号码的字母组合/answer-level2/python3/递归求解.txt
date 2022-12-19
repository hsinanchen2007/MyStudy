### 解题思路
递归求解，算出来子字符串的情况，然后与当前字符合并

### 代码

```python
class Solution:
    digitsDict = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z'],
    }
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return self.digitsDict[digits]
        result = []

        subResult = self.letterCombinations(digits[1:])

        for c in self.digitsDict[digits[0]]:
            for sub in subResult:
                result.append(c+sub)
        
        return result
```