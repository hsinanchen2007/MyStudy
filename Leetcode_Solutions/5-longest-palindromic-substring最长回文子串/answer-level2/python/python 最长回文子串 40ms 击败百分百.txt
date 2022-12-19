改进中心移动扩展，回文长度分奇数偶数单独考虑，可先只中心移动扩展查找偶数长度回文，找完之后再按查找到的最长偶数回文长度+1查找奇数回文长度，减少查找量，最快可达40ms，击败百分百。有兴趣可以查看[博客](https://blog.csdn.net/qq_33758867/article/details/90031889)，小白相互学习，共同进步。
```
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) < 2 or s == s[::-1]:
            return s

        length = 1

        even_medium = 0
        even_left = 0
        for i in range(len(s) - 1):
            if i - even_left >= 0 and s[i - even_left] == s[i + 1]:
                substring = s[i - even_left: i + 2]
                if substring == substring[: : -1]:
                    even_medium = i
                    length = even_left + 2
                    even_left = even_left + 2

        odd_medium = 0            
        half = (length + 1) // 2
        odd_left = (length + 1) // 2
        for j in range(half, len(s) - half):
            if j - odd_left >= 0 and s[j - odd_left] == s[j + half]:
                substring = s[j - odd_left: j + half + 1]
                if substring == substring[: : -1]:
                    odd_medium = j
                    length = odd_left + half + 1
                    odd_left = odd_left + 2

        if length % 2 == 0:
            return s[even_medium + 2 - length: even_medium + 2]
        else:
            if length == 1:
                return s[0]
            else:
                return s[odd_medium + half + 1 - length: odd_medium + half + 1]
```
