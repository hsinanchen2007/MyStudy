class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return '1'
        else:
            a = 2
            s = '1'
            while a <= n:
                l = ''
                count = 1
                for i in range(0, len(s) - 1):
                    if s[i + 1] == s[i]:
                        count += 1
                    else:
                        l += (str(count) + s[i])
                        count = 1
                l += (str(count) + s[-1])
                s = l
                a += 1
            return l