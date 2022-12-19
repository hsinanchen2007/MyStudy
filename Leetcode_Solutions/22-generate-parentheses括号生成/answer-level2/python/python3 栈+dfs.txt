### 解题思路
括号匹配的问题可以用栈来解决
对于这种策略问题，可以用强化学习......啊复习晕了，可以用dfs来搜索可以实现的策略

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        #栈+dfs试试
        #因为是一个策略问题，所以考虑dfs
        #用栈的匹配来解决括号匹配
        res = []
        def dfs(num_a,num_b,stack,str_):
            #如果a和b用完并且此时栈为空的话，说明成功了
            if num_a == num_b == 0 and stack == []:
                res.append(str_)
                return 
            #每次向两个方向搜索，即放a和放b
            if num_a > 0:
                dfs(num_a -1,num_b,stack + ['a'],str_ + '(')
            #放b则需要满足一定条件
            if stack and stack[-1] == 'a':
                stack.pop()
                dfs(num_a,num_b - 1 , stack,str_ + ')')
        
        dfs(n,n,[],str_ = '')
        return res
            
```