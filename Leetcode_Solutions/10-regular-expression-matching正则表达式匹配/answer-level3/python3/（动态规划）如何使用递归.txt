```
代码块
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        memo = {}
        def df(i,j):
            if (i,j) not in memo: # 如果memo有记录则直接取用
                if j >= len(p): # 模式串到达末尾，此时结果为 被匹配串 是否匹配到末尾
                    ans = i == len(s)
                else: #如果模式串未到达末尾
                    first_match = i < len(s) and p[j] in [s[i] , '.'] # 当前位是否匹配
                    if len(p[j:])>=2 and p[j+1] =='*': # 模式串当前位的下一位为'*',且'*'位后仍有字符未匹配
                        ans = df(i , j+2) or (first_match and df(i+1 , j))
                    else: # 模式串后一位不是'*',则正常匹配，都向后移一位
                        ans = first_match and df(i+1, j+1)
                memo[(i,j)] = ans # 将(i,j)当前所得结果存储进memo
            return memo[(i,j)] # 返回当前结果
        
        return df(0,0)
```

需注意每一步的判断条件