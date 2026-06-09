### 解题思路

这道题用递归做会不可避免地多次在s中寻找同一个子串出现的位置，因此可以干脆把p分为多个待匹配的子串并求出这些字串出现的所有位置，再分析是否能将这些位置中组合出一个原串的子序列。这段代码当然是可以优化的，比如可以用KMP寻找子串，或者对于不同p中子串应用不同寻找起点。当然由于本题数据量不大，现在的复杂度也是足够的。

一个非常有用的trick是在字符串开头与借位加上特殊标识符，避免单独处理'*'开头、结尾的情况。这个trick在许多类似的“正则表达式匹配”题目中都是适用的。

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s='^'+s+'$'
        p='^'+p+'$'
        p=filter(lambda x:x!='',p.split('*'))
        indexes=[fit(s,i) for i in p]
        # print(indexes)
        tail=0
        for i in indexes:
            for j in i:
                if j[0]>=tail:
                    tail=j[1]
                    break
            else:
                return False
        return True

def fit(s,p):
    index=[]
    for i in range(len(s)-len(p)+1):
        for j in range(len(p)):
            if s[i+j]!=p[j] and p[j]!='?':
                break
        else:
            index.append((i,i+len(p)))
    return index

```