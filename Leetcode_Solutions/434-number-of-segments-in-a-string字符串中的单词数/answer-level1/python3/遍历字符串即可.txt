**一定要仔细读题，什么是单词。这里的单词指的是连续的不是空格的字符。
所以说出了空格的其他字符都可认定为单词。**
首先我们判断s为空的情况
然后遍历该字符串，如果遇到非空格字符，把flag标记置为1，说明遇到单词了。
然后在下一次遇到空格的时候，把该单词加到结果ans中，并把flag标记置为0
然后在最后判断一下最后一个单词的问题，因为最后一个单词后面不会有空格。
时间复杂度O(N)
空间复杂度O(1)
```
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == '':
            return 0
        flag = 0
        ans = 0
        for item in s:
            if item != ' ':
                flag = 1
            elif flag == 1 and item == ' ':
                ans += 1
                flag = 0
        if s[-1] != ' ':
            return ans + 1
        else:
            return ans
        
```
