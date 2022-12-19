这题的意思是需要根据一个字符串复原所有可能ip，而一个ip有4段，直接进行分隔的话有太多可能性，而且会有很多次重复判断ip段。所以我的思路是将字符串分成2部分。这样每一部分只需要再分成两段分别判断是否符合ip规则即可，最后将所有符合的ip段进行拼接即可，而不用像1个完整字符串切割4段一样需要考虑太多情况。

效率确实还可以
![WX20200301-235026@2x.png](https://pic.leetcode-cn.com/9599a9824d7b822c59c98918482b76e4ed4a5c086610eb628c3313f23e100783-WX20200301-235026@2x.png)

下面是代码：
```
class Solution(object):
    def restoreIpAddresses(self, s):
      
        if len(s) > 12 or len(s) < 4:
            return []

        length = len(s)

        left = []
        right = []
        result = []
        for j in range(2, length - 1):
            # 左部分所有符合规则的ip段
            left = self.classify(s[:j])
            # 右部分所有符合规则的ip段
            right = self.classify(s[j:])
            for l in left:
                for r in right:
                    result.append(l + "." + r)

        return result


    def classify(self, s):
        length = len(s)
        result = []
        for i in range(1, length):
            # 当分割的两部分都符合ip段的规则，就进行拼接
            if self.judge(s[:i]) and self.judge(s[i:]):
                result.append(s[:i] + "." + s[i:])


        return result


    def judge(self, s):
        # 这个函数是用来判断字符串是否符合ip段规则
        if len(s) > 3 or s == "":
            return False

        if s.startswith("0") and len(s) > 1:
            return False

        if int(s) > 255:
            return False

        return True
```
