![image.png](https://pic.leetcode-cn.com/32eba3050f4df81ecef734184e857790ae3d785c3528bd859e9daa9bce567f55-image.png)
### 解题思路
递归
假设组合abc
**递**
f(abc) -> comb(a,f(bc))
f(bc) -> comb(b,f(c))
f(c) -> comb(c,'')
**归**
comb(c,'') -> c
abc 组合b,c
comb(b,c) -> b
ab 组合a,b
comb(a,b) -> a

我觉得跟遍历没啥区别，没想到还是快一点

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_dic = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}

        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return self.combine(letter_dic[digits[0]],'')

        return self.combine(letter_dic[digits[0]],self.letterCombinations(digits[1:]))
        



    def combine(self,a,b):
        com = []

        if b == '':
            for c1 in a:
                com.append(c1)
        else:
            for c1 in a:
                for c2 in b:
                    com.append(c1+c2)
        return com
```