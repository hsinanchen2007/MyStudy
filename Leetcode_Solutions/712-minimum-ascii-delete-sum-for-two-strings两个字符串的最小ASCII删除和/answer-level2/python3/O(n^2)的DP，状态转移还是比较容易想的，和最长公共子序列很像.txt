### 解题思路
![QQ截图20200406183828.png](https://pic.leetcode-cn.com/2c8e773ddf384882832147caa6ae7926ed298da4fa02c027060f656c40690acb-QQ%E6%88%AA%E5%9B%BE20200406183828.png)

DP状态定义成题目所求即可，即：dp[i][j]表示s1[0...i]和s2[0...j]的“*使两个字符串相等所需删除字符的ASCII值的最小和*”

状态转移规则也比较简单，假如s1[i]!=s2[j],那么，要么是s1[i]是待删除的，要么是s2[j]是待删除的，到底删除哪一个就看是哪一个字符加到分别对应的上一个dp上能使当前dp最小；当s1[i]==s2[j]时，s1[i]/s2[j]一定不能被删除，所以dp[i][j]也就是dp[i-1][j-1]

状态转移方程：
dp[i][j]={
min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j])....if s1[i]!=s2[j]
dp[i-1][j-1].................................if s1[i]==s2[j]
}


累死了，不练了
### 代码

```python3
import functools
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m=len(s1)
        n=len(s2)
        dp_mindel=[[0 for i in range(n)] for i in range(m)]
    
        if s1[0]==s2[0]:
            dp_mindel[0][0]=0
        else:
            dp_mindel[0][0]=ord(s1[0])+ord(s2[0])

        for i in range(1,m):#第一列初始化
            if s2[0] in s1[0:i+1]:
                dp_mindel[i][0]=functools.reduce(lambda x, y: x + y, [ord(each_char) for each_char in s1[0:i+1]])-ord(s2[0])#先对串里每个字符ord再组成列表并对列表元素累加
            else:
                dp_mindel[i][0]=functools.reduce(lambda x, y: x + y, [ord(each_char) for each_char in s1[0:i+1]])+ord(s2[0])

        for j in range(1,n):#第一行初始化
            if s1[0] in s2[0:j+1]:
                dp_mindel[0][j]=functools.reduce(lambda x,y:x + y , [ord(each_char) for each_char in s2[0:j+1]])-ord(s1[0])
            else:
                dp_mindel[0][j]=functools.reduce(lambda x,y:x+y,[ord(each_char) for each_char in s2[0:j+1]])+ord(s1[0])

        #DP：
        for i in range(1,m):
            for j in range(1,n):
                if s1[i]==s2[j]:
                    dp_mindel[i][j]=dp_mindel[i-1][j-1]
                else:
                    dp_mindel[i][j]=min(dp_mindel[i-1][j]+ord(s1[i]),dp_mindel[i][j-1]+ord(s2[j]))

        return dp_mindel[m-1][n-1]


```