### 解题思路
每次取出一个数字，遍历数字对应的字母，每次遍历将字母添加到每个已经组好的字符串中。
当数字取完时return

### 代码

```python3
class Solution:
    def letterCombinations1(self,digits:str,i:int,ss:str)-> List[str]:
        change = {
            '2':'abc',
            '3':'def',
            '4':'ghi',
            '5':'jkl',
            '6':'mno',
            '7':'pqrs',
            '8':'tuv',
            '9':'wxyz'}
        if i == len(digits):
            return ss
        else:
            ws = []
            k = ''
            if len(ss) == 0:
                for d in change[digits[i]]:
                    ss += d
            else:
                for w in ss:
                    for d in change[digits[i]]:
                        k = ''.join([w,d])
                        ws.append(k)
                ss = ws
            return self.letterCombinations1(digits,i+1,ss)

    def letterCombinations(self, digits: str) -> List[str]:
        ss = []
        i = 0
        return self.letterCombinations1(digits,i,ss)
    
                        



```