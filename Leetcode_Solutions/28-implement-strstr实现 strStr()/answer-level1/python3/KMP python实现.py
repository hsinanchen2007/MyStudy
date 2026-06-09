主要就是求next的思路，一个是在next[0]处加入哨兵，另一个是根据字符串的长度遍历，最后一个是模式串与模式串错开一位匹配即可求next数组，精简一下，就是只需要在不相等的情况下做特殊处理即可，不相等的情况在循环里判断，熟悉KMP有助于熟悉AC自动机，因为AC自动机=trie+KMP
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        ne = [-1 for _ in range(len(needle)+1)] #ne[k]存储长度为k的字符串的最长公共前后缀长度
        if len(needle) > 0:
            ne[1] = 0
        j = 0
        for i in range(2,len(needle)+1): #遍历字符串长度，前两个长度已经初始化，因此从长度2开始遍历
            #错开一个字符匹配即可顺序得到所有长度下的公共前后缀长度
            while j >= 0 and needle[j] != needle[i-1]:
                j = ne[j]
            j += 1
            ne[i] = j
        #KMP过程和上述相同，只是匹配待匹配字符串，而不是模式串错开一位,且不用对next数组赋值
        j = 0
        for i in range(len(haystack)):
            while j >= 0 and haystack[i] != needle[j]:
                j = ne[j]
            j += 1
            #判断是否可以结束
            if j == len(needle):
                return i-len(needle) + 1

        return -1
```
