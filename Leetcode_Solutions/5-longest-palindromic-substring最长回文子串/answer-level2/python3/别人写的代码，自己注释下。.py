[@powcai](https://leetcode-cn.com/u/powcai) 三种思路：

（ 一）：中心扩展法，这里要考虑两种情况，回文串的长度为奇数或者偶数情况。

（二）： 把每个字母当成回文串的结束。

（三）： 动态规划。 dp[i][j] 表示字符串从 j 到 i 是否是为回文串，即当 s[j] == s[i] 如果 dp[i-1][j+1] 也是回文串，那么字符串从 j 到 i 也是回文串，即 dp[i][j] 为真。


第一种
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        self.strhui = ''
        #函数里面定义一个函数
        def July(i, j):
            while i>=0 and j<n and s[i]==s[j] :
                i -= 1
                j += 1
            #if语句中的j,i是while里面运行后的
            if len(self.strhui) < j-i-1 :
                self.strhui = s[i+1 : j]
        for i in range(n):
            #回文数为偶数和奇数
            July(i,i)
            July(i,i+1)
        return self.strhui
```

第二种
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_len = 1
        start = 0
        n = len(s)
        #遍历每一个字符，并假设为回文数的尾字符
        for i in range(1,n):
            #偶数取序号i前面 max_len个字符，奇数取i前面max_len+1个字符。i+1表示取到序号i字符
            even = s[i - max_len : i+1]
            odd  = s[i - max_len - 1 : i+1]
            # 1 判断 取到的字数组下标，并且是回文数
            # 2 给start赋值，奇数字串max_len加2,偶数字串max_len加1
            if i-max_len >=0 and even == even[::-1] :
                start = i-max_len
                max_len += 1
            elif i-max_len - 1 >= 0 and odd == odd[::-1] :
                start = i - max_len -1
                max_len += 2
        
        return s[start:start+max_len]
        
```
第三种，动态规划
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s :
            return ''
        #动态规范法
        n = len(s)
        #若dp[i][j] 等于1，代表字符j到i是回文，若为0，则不是。*注意i>j
        dp = [[0]*n for i in range(n)]
        max_len = 0
        #两个for循环，实现:对每一个i,使得j取值范围为[0,i]。即[0,i],[1,i] ... [i,i]
        for i in range(n):
            for j in range(i,-1,-1):
                #在上面所讲的i,j取值内，有s[i] == s[j] 。这个是设定的触发条件，两个值相等才能是回文数
                #设条件x为: i-j <2 ，代表j可以取值i,i-1    程序刚执行时，确保任意i对应单个字符为回文，
                #设条件y为: dp[i-1][j+1]值为1 ,代表可以抛弃 i-j<2 的条件。j可以取到所有值[0,i]
                if s[i] == s[j] and (i-j <2 or dp[i-1][j+1]) :
                    dp[i][j] = 1
                # 第一遍循环 max_len = 1 
                if dp[i][j] == 1 and max_len < i-j+1 :
                    res = s[j:i+1]
                    max_len =i-j+1
                #对于回文为偶数个,'jkllkj', 程序在i取到右边的l时，比较左边的l相等，触发条件同时x条件成立。后面依次比较
                #。。。。。奇数个,'abpba' , 程序在i取到右边的b时，比较左边的b相等，触发条件同时y条件成立。后面依次比较
        return res
                    
        
        
        
```
