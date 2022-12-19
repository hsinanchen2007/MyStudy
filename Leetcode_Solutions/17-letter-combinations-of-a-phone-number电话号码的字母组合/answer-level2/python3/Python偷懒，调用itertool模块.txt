### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        import itertools
        arr = []
        res = []
        if not digits:
            return res
        nDict = {
            '2':'abc', '3':'def', 
            '4':'ghi','5':'jkl', '6':'mno', 
            '7':'pqrs', '8':'tuv', '9': 'wxyz'
        }
        for s in digits:
            arr.append(nDict[s])
        for i in list(itertools.product(*arr)):
            s = ''.join(i)
            print(s)
            res.append(s)
        #print(arr)
        #print(list(res))
        return res
        
```