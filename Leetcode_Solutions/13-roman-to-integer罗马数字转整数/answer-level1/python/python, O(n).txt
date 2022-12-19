从第一个字符开始扫描
每一循环看两个字符
如果前一个字符小于后一个字符，那么此时减去前一个字符的对应数字
如果大于或者等于则加上前一个字符的对应数字

```
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.mydict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        num = 0
        for i in range(len(s)-1):
            j = i+1
            if self.mydict[s[i]] < self.mydict[s[j]]:
                num = num - self.mydict[s[i]]
            else:
                num += self.mydict[s[i]]
        num += self.mydict[s[len(s)-1]]
        return num
```

