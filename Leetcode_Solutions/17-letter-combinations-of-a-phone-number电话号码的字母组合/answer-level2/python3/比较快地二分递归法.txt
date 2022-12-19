### 解题思路
这个题目回溯法比较主流，我才用了对输入字符串进行二分递归地办法。
这样会随着输入增加效率更快！

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dicts = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        lens = len(digits)
        if lens>1:
            mid = lens // 2
            res1 = self.letterCombinations(digits[0:mid])
            res2 = self.letterCombinations(digits[mid:])
            result = []
            for i in res1:
                for j in res2:
                    result.append(i+j)
            return result
        elif lens==1:
            return list(dicts[digits[0]])
        elif lens==0:
            return ''
```