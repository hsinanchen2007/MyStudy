### 解题思路
自己刷题做笔记题解，大神们勿喷

动态规划思想：
先思考状态转化过程，比如说一个字符串s，dp[i]表示到s[i]一共有多少种方法。
因为需要解码的数字是从1-26，那么解码一次可能是一位数也可能是两位数
那么s[i]就可能前一个状态是解码1一个数字过来的，也可能是解码2数字过来的，
所以dp[i] = dp[i-1] + dp[i-2]，这是基本的状态转移方程。

要考虑特殊情况，第一种如果s[i]=0:
那么只有10/20可以被解码，那么dp[i]=dp[i-2],解码两位到达当前位，
如果出现了30/40/50这样子，那么必然是无法到达的，需要直接返回0
```
if s[i] == '0':
    if s[i-1] not in ['1','2']:
        return 0
    else:
        dp[i] = dp[i-2]
```
为什么不考虑0和s[i+1]的组合情况呢，因为01/02这样的本来就不存在，
遇到0只需要考虑前一位就行了

那么当s[i]!=0的时候：
需要当前位是怎么过来的，如果s[i-1]+s[i]可以组合出11-26（除去20）这样的情况：
那么他就有两种情况，解码1位过来或者解码两位过来，就满足状态转移方程了。

‘s[i-1]+s[i]可以组合出11-26（除去20）这样的情况’ 那么怎么才能形成这种条件呢？
在s[i]!=0的条件,三种情况：
a: s[i-1] = 1 s[i]为任何数都可以
b: s[i-1] = 2 s[i] 处于[1,6]才可以,其他数字就只能解码1位到达s[i]了，dp[i]=dp[i-1]
c: s[i-1] = 其他，那么就只能解码1位过来了，dp[i]=dp[i-1]
那么就可以把这两种满足状态转移方程的条件写出来：
```
if s[i]!='0':
    # a: s[i-1] = 1 s[i]为任何数都可以
    if s[i-1] == '1':
        dp[i] = dp[i-1]+dp[i-2]

    else:
        # b: s[i-1] = 2 s[i] 处于[1,6]才可以,其他数字就只能解码1位到达s[i]了，dp[i]=dp[i-1]
        if s[i-1] == '2':
            if 1<=int(s[i])<=6:
                dp[i] = dp[i-1]+dp[i-2]
            else:
                dp[i] = dp[i-1]

        # c: s[i-1] = 其他，那么就只能解码1位过来了，dp[i]=dp[i-1]
        else:
            dp[i] = dp[i-1]
```
最终返回dp[-1]就ok了。
害，一道题半天，心累。
解题里看到很清晰的一张图
![image.png](https://pic.leetcode-cn.com/3b29bfae0ce705a19a0c5ef3e73ea3293b5c853ad36e22a323698fa25fdc9190-image.png)


### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        
        # 到S[i]时的解码方式 dp[i],两种路径：dp[i-1]+1解码过来的。dp[i-2]+2解码过来的
        '''
        dp[i] = dp[i-1]+dp[i-2]
        '''
        
        lenS = len(s)
        dp = [0 for i in range(lenS)]

        dp[-1] = 1
        if s[0] == '0':
            return 0
        else:
            dp[0] = 1

        for i in range(1,lenS):
            if s[i] == '0':
                if s[i-1] not in ['1','2']:
                    return 0
                else:
                    dp[i] = dp[i-2]
            else:
                if s[i-1] == '1':
                    dp[i] = dp[i-1]+dp[i-2]

                else:
                    if s[i-1] == '2':
                        if 1<=int(s[i])<=6:
                            dp[i] = dp[i-1]+dp[i-2]
                        else:
                            dp[i] = dp[i-1]
                    else:
                        dp[i] = dp[i-1]
        return dp[lenS-1]
```