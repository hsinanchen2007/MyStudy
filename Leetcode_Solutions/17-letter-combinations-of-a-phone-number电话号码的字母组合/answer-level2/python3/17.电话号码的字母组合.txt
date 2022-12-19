### 解题思路
- 穷举
- 构建一个字典，用于取出字母，然后穷举

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:return []
        nums_to_string = {'2':"abc",'3':"def",'4':"ghi",'5':"jkl",'6':"mno",'7':"pqrs",'8':"tuv",'9':"wxyz"}
        originals = [nums_to_string[num] for num in digits ]
        res = ['']
        for original in originals:
            res = [a+b for a in res for b in original]
        return res
```