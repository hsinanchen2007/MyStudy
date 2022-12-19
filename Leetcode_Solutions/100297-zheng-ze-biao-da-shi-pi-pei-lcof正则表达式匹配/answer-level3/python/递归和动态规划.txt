### 解题思路
注释里是递归的方法

还可以用分类讨论下的动态规划，思维上需要比较缜密
dp[i][j]表示的是s的前i项和p的前j项是否匹配

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
#         # p为空的时候, 如果s也是空的那就是true，如果s非空就是false
#         if not p: return not s 
        
#         first_match = bool(s and p[0] in {s[0], "."})
        
#         if len(p) > 1 and p[1]=="*":
#             return self.isMatch(s,p[2:]) or (first_match and self.isMatch(s[1:], p))
#         else:
#             return first_match and self.isMatch(s[1:],p[1:])
          
        dp = [ [False for i in range(len(p)+1)] for j in range(len(s)+1)]
        
        dp[0][0] = True
        for index in range(2,len(p)+1):
            c = index - 1
            if p[c] == "*":
                dp[0][index] = dp[0][index-2]
    
        for i in range(1,len(s)+1):
            for j in range(1,len(p)+1):
                # 当前字符匹配
                # 因为角标和i，j的定义不太一样，所以需要处理一下
                s_ = i-1
                p_ = j-1
                if s[s_] == p[p_] or p[p_] == ".":
                    dp[i][j] = dp[i-1][j-1]
                
                # 当前字符为星号
                if p[p_] == "*":
                    # 如果前面字符匹配
                    if s[s_] == p[p_-1] or p[p_-1] == ".":
                        # 可能匹配0个或者多个的情况，任意一种为真都可以
                        dp[i][j] = (dp[i][j-2] or dp[i-1][j])
                    else:
                        dp[i][j] = dp[i][j-2]
                     
        return dp[len(s)][len(p)]

            
            
            

```