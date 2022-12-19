### 解题思路
利用回溯算法，将不同数字代表的各字符串元素进行组合

### 代码

```python3
class Solution:
    
    def letterCombinations(self, digits: str) -> List[str]:
        numToLetter = {'2': 'abc', '3': 'def', '4': 'ghi',
                        '5': 'jkl', '6': 'mno', '7': 'pqrs',
                        '8': 'tuv', '9': 'wxyz'}
        if len(digits)<1:
            return []
        elif len(digits)==1:
            return [x for x in numToLetter[digits]]
        else:
            result = []
            len_n = len(digits)
            def backTrack(i=0,S=''):
                if i>len_n-1:
                    result.append(S)
                else:
                    element = numToLetter[digits[i]]
                    for j in range(len(element)):
                        backTrack(i+1,S+element[j])

            backTrack(0)
            return result
            
```