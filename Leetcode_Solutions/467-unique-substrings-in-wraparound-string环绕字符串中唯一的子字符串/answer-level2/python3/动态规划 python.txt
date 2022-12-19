### 解题思路
dp[i]表示以i位置的字母作为字符串结尾的最长连续字符串的长度
dp[i] = max(dp[i],k)

k表示以p[i]作为此时连续字符串的末尾时，该字符串的长度，

对于连续字符串中断后的首字符，比如"a...zbcd...za"，b是中断的开始字符，即新开始一个连续字符串，此时k=1，
那么当计算后面一个字符c的dp时，需要比较原先的dp[c]=3和此时的这个c处于连续字符串的第几个位置即k=2，取较大值
对于最后一个字符a，它处于连续字符串"bcd...za"中，此时k=26，但是dp[a]=1,所以这时候可以取k的值

最后对所有dp[i]求和即为非空子串个数

### 代码

```python
class Solution:
    # dp[i] = max(dp[i-1],dp[i])
    # 这种方法是错误的
    # 如果p="abczcd"
    # dp[c]=3，对于末尾碰到的d来说，dp[c]=3不变,但是dp[d]=4，因为d前面的c以3作为他自己的长度了，而实际上他此刻只是1
    # 以上方法会导致多记次数
    def findSubstringInWraproundString(self, p: str) -> int:
        if len(p) == 0:
            return 0
        # dp[i]记录以每一个字母结尾的最长字符串长度
        dp = [0 for _ in range(26)]
        dp[ord(p[0])-ord('a')] = 1
        # 作为标记记录此时的连续字符串长度
        k = 1
        for i in range(1,len(p)):
            if (ord(p[i])-ord(p[i-1])+26)%26 == 1:
                k += 1
                dp[ord(p[i])-ord('a')] = max(dp[ord(p[i])-ord('a')],k)
            else:
                k = 1
                if dp[ord(p[i])-ord('a')] == 0:
                    dp[ord(p[i])-ord('a')] = 1

        sum_val = 0
        for i in dp:
            sum_val += i
        return sum_val

```