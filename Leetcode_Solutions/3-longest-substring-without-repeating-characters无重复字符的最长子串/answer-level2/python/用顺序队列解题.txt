把字符串里的字符分别放入一个顺序队列中，遇到重复的字符则把队列中从开头到重复的字符裁剪掉，
此时的队列便是符合题目要求的列表，统计该队列的最大长度即可。

```
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max = 0
        list01 = []
        for i in s:
            if i in list01:
                while True:
                    if list01.pop(0) == i:
                        break
            list01.append(i)
            if max < len(list01):
                max = len(list01)
        return max
```
