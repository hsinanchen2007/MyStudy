对字符串中每个子串进行遍历提取，并判断是否是回文子串，如果是跟之前判断的回文子串进行length对比，如果大于，则存储，小于则继续进行遍历。
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        result = str()
        for i in range(length):
            sum1 = str()
            sum2 = str()
            for str1 in s[i:]:
                sum1 = sum1 + str1
                sum2 = str1 + sum2
                if sum1 == sum2 and len(sum1)>len(result):
                    result = sum1
                else:
                    continue
        return result
```

设置一个容器，用来存储长度最长的回文子串