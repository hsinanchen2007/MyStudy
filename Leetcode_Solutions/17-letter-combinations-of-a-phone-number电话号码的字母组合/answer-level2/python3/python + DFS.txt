```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # create a dictionary
        # dfs traverse each digit
        # end-up condition: length == len(digits)
        # Time complexity: O(N)

        dic = {
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
        def get_combinations(index, temp_str):
            if len(temp_str) == len(digits):
                res.append(temp_str)
                return
            for s in dic[digits[index]]:
                get_combinations(index + 1, temp_str + s)
        if digits == '': return [] # Corner case
        get_combinations(0, '')
        return res
```