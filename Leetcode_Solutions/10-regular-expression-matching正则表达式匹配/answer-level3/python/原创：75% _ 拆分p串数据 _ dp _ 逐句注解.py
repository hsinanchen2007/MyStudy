### 举例：如何拆分p串数据
`拆分p串的数据` eg:"c*a*b" -> **b and ca
`优势`: 这样 * * b 串中每个字符至少会使用一次，不匹配时立即返回False或(*的零次匹配)，可以简化逻辑顺便剪枝

> 这样处理后，逻辑分支仅有四个，见注解 #情况i
### 代码

```python3
import functools
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        self.s  = s
        self.p = []
        self.buff = []
        # 整理数据
        # self.s 为原s串
        # self.p ： 当出现x* or .* 时只储存*，在self.buff中找 x 与 .
        # self.buff : 当出现x* or .* 时储存 x 与 .
        for i in range(len(p)):
            if p[i] == '*':
                self.p.pop(-1)
                self.p.append(p[i])
                self.buff.append( p[i-1])
            else:
                self.p.append(p[i])

        # 使用lru缓存，使递归变dp
        @functools.lru_cache(10000)
        def dp(i,j,k):
            if i == len(self.s) and j == len(self.p):return True
            if j >= len(self.p) : return False  # p先匹配完必为False，因为s都是定长的（没有.or *）
            if i>= len(self.s) and j< len(self.p): return ['*']*(len(self.p)-j) == self.p[j:] # 若s先匹配完，而p尚有剩余，若此时所余均为 x* 则返回True; 匹配失败为False
            if i>= len(self.s) : return False # p无剩余，故为False
            if self.p[j] == '*':  # p串遇到 * 时
                if self.s[i] == self.buff[k] or (k<len(self.buff) and self.buff[k] == '.'):
                    # 情况 1
                    return (
                        # 由于x与s[i]匹配，故匹配 x* 的次数不同有不同选择
                        dp(i,j+1,k+1) # zero times 
                        or dp(i+1, j+1, k+1) # one times
                        or dp(i+1,j,k) # one more times
                    )
                else:
                    # 情况 2
                    # 由于x与s[i]不匹配，故只能使*匹配零次
                    return dp(i,j+1,k+1) # zero times
            if self.s[i] == self.p[j] or self.p[j] == '.' :
                # 情况 3
                return dp(i+1, j+1 , k) # 当前匹配成功，进入下次匹配
            else:
                # 情况 4
                return False #当前必定不匹配，因为经过整理的self.p中的所有字母至少会使用一次

        return dp(0,0,0)

```