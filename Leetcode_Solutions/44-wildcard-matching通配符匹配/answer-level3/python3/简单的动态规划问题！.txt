'''
这题比较简单
我们只要分类讨论*=0，1，2 。。。就可以得到答案了

'''


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        x = len(s)
        y = len(p)

        if x == 0 or y == 0:
            if x == 0 and y == 0:
                return True
            elif x != 0 and y == 0:
                return False
            else:
                for i in p:
                    if i != "*":
                        return False
                return True



        dp = [[False for _ in range(y + 1)] for _ in range(x + 1)]

        dp[0][0] = True

        for i in range(y):
            if p[i] != "*":
                break
            for e in range(x+1):
                dp[e][i+1] = True
                
        '''
        这里我们要特殊处理一下开头都是*的情况。
        要知道，如果只有一个*，那么他和任何匹配都是true，因此 当p[0]=*的时候， dp[i][0] 表示用s[i] 去匹配 *， 因此恒为true
        为防止多个*在开头，我们就从头遍历p，直到*都消耗完为止。
        '''


        for i in range(1, x + 1):
            for j in range(1, y + 1):
                if p[j - 1] != "*":
                    dp[i][j] = dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == "?")
                    '''
                    当没有*的时候，匹配上的条件就是， 末尾元素对应相同， 要么p最后元素为？，并且前面的必须还要都匹配上
                    '''
                else:
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j - 1] or dp[i - 1][j]
                    '''
                    dp[i][j-1]表示 * = 0， 即s[：i]和p[:j-1]本来就是匹配好的，那么p[j] == "*" 就没卵用了
                    dp[i-1][j-1] 表示 * = 1 这时候 * 和 ？一样的条件
                    dp[i-1][j] 表示 * >=2 这时候就延续之前的结果就行了.（这点比较难理解，但第10题已经讲的很清楚了）
                    
                    关键点在于三个条件是或的关系。
                    
                    
                    '''

        return dp[-1][-1]

foo = Solution()
print(foo.isMatch(
"ho",
"**ho"))