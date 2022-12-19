### 解题思路
利用回溯法，从头至尾遍历字符串，将每一个数字字符对应的字符加入combination中，直至所需处理的字符串长度为0，此时将结果字符串加入结果列表中。即回溯的终止条件是所需处理的字符串长度为0。

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numToStr = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        def backtrack(combination, digitstr):
            if len(digitstr)==0:
                output.append(combination)
            else:
                for i in numToStr[digitstr[0]]:
                    backtrack(combination+i, digitstr[1:])
        output = []
        if digits:
            backtrack('', digits)
        return output
```