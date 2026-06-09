```

'''

定义state： dp[i] 表示： 若s[i]处是一个合法字符， 则dp[i] == True

DP 转移方程：
    若s[i] 是个合法的" ）"字符, 其必然与前面的某个"（ "是一对：
    设这个与其配对的"（" 是字符 s[j]
    
    则s[i]和s[j]组成一对合法字符的条件是：
    若假设 j 在前， i在后
    1. s[j] == "(" .  s[i] == ")"      你要凑一对啊
    2. s[j+1:i-1]一定是合法字符, 即i和j之间的全部内容都是合法字符
    3. dp[j] == False, 即说明 s[j] 的这个 "（ "并没有跟其他"）"配过对。 即未婚
    
    这个适合 i 和 j 就可以凑成一对了。
    
    
    得到的DP就是一个true false的序列。例如： T F F T T T
    我们只要找到这个序列里面最长的连续 True序列就行了。
        

'''




class Solution:
    def longestValidParentheses(self, s: str) -> int:
        size = len(s)
        dp = [False for _ in range(size)]

        for i in range(1, size):
            if s[i] == ")":      #开始配对
                j = i-1

                while j >= 0:    #向前找 " ( "
                    if dp[j] == True: #如果前面都配好对了（都是合法的，就继续往前找
                        j = j-1
                    elif s[j] == "(": #自后向前找到的第一个未婚字符，还是个 ( 的话，与其配对。，
                        dp[j] = True
                        dp[i] = True

                        break   #找到了不要继续找了
                    else:
                        break  #如果遇见的第一个未婚字符不是（ 的话，该 ）就无法完成配对了。

        i = -1
        maxlength = 0
        '''
        寻找最长连续true序列
        
        连续序列的计数问题；
        两个while循环
        外循环是起始点（条件为起始点小于size）
        内循环是runlength（条件为：index不超过，且符合计数条件）
        
        注意：
        1. runlength 必须从1开始，不然没法更新
        2. 记得在外循环的结尾更新搜索起始点，内循环结尾更新runlength
        '''
        while i < size:
            runlength = 1
            while i+runlength < size and dp[i+runlength]:
                runlength += 1
            if runlength-1 > maxlength:
                maxlength = runlength-1

            i = i + runlength


        if maxlength > 1 :
            return maxlength
        else:
            return 0



foo = Solution()
print(foo.longestValidParentheses(")"))

```
