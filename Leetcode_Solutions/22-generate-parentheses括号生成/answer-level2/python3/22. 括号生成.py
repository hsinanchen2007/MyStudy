### 解题思路
排列组合的题目一般可以用回溯法求解，关键在于剪枝。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int):
        output=[]
        def f(combination,num,n,len1,len2):
            if len1<len2 or len1>n:
                return
            if num==0:
                output.append(combination)
                return
            f(combination+'(',num-1,n,len1+1,len2)
            f(combination+')',num-1,n,len1,len2+1)
        f('',n*2,n,0,0)
        return output

```