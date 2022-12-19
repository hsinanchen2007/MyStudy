### 解题思路
1.直接使用列表表达式+循环解决：注意要对res赋初值
2.递归：长度为n的字符串的输出应当为长度为n-1的字符串的输出的每个元素后加上不同字母

### 代码

```python3
class Solution:
    """
    def __init__(self):
        self.dict1 = {'1':[''], '2':['a', 'b', 'c'], '3':['d', 'e', 'f'], 
                  '4':['g', 'h', 'i'], '5':['j', 'k', 'l'], '6':['m', 'n', 'o'], 
                  '7':['p', 'q', 'r', 's'], '8':['t', 'u', 'v'], '9':['w', 'x', 'y', 'z']}
    """
    def letterCombinations(self, digits: str) -> List[str]:
        # 直接使用列表表达式+循环
        dict1 = {'1':'', '2':'abc', '3':'def', 
                 '4':'ghi', '5':'jkl', '6':'mno', 
                 '7':'pqrs', '8':'tuv', '9':'wxyz'}
        lens = len(digits)
        res = []
        if lens == 0:
            return res
        else:
            res = [j for j in dict1[digits[0]]]
            for k in digits[1:]:
                res = [i+j for i in res for j in dict1[k]]
        return res

        # 递归:长度为n的字符串的输出应当为长度为n-1的字符串的输出的每个元素后加上不同字母
        """
        lens = len(digits)
        if lens == 1:
            return self.dict1[digits]
        elif lens == 0:
            return []
        else:
            k_1 = self.letterCombinations(digits[0:lens-1])
            k = []
            for i in self.dict1[digits[-1]]:
                k += [j+i for j in k_1]
            return k
        """
```