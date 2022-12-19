1. 扫描一边序列，利用动态规划记录到每个字符为止的最长子序列长度。
2. 时间复杂度o(n),空间复杂度o(1)
```
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        if not p:
            return 0
        len_string = [0] * 26 #记录到这个字符为止的最长子序列长度
        len_string[ord(p[0])-ord('a')] = 1
        dp = 1 #记录到目前为止的最长子序列长度
        n = len(p)
        for i in range(1,n):
            #更新dp
            if ord(p[i]) - ord(p[i-1]) == 1 or ord(p[i]) - ord(p[i-1]) == (-25): #如果p[i]和p[i-1]相邻
                dp += 1
            else:
                dp = 1
            #更新len_string
            len_string[ord(p[i])-ord('a')] = max(len_string[ord(p[i])-ord('a')],dp)       
        #根据len_string统计结果
        return sum(len_string)
```
