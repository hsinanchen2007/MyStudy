### 解题思路
本题借鉴之前正则表达式匹配的思路做的，分析字符串i指针和模式串j指针之间的关系：
1. 成功匹配情况，都到了字符串末尾+1；
2. 模式串j指针当前是与i指向的字符相同，或者是？，或者是*,first_match为True；
3. 如何j指针当前指向*，那么*可以为空，j去下一个，也可以匹配当前i指针，i去下一个;
4. j指针指向的不是*，那么就同步向下一个。

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}
        def match(i,j):
            if (i,j) not in memo:
                if j == len(p):
                    ans = i == len(s)
                else:
                    first_match = i<len(s) and p[j] in {s[i],'?','*'}
                    if j<len(p) and p[j]=='*':
                        ans = match(i,j+1) or first_match and match(i+1,j)  #*为空，或者*能配对1个字符
                    else:
                        ans = first_match and match(i+1,j+1)
                memo[i,j]=ans
            return memo[i, j]
        return match(0,0)
```