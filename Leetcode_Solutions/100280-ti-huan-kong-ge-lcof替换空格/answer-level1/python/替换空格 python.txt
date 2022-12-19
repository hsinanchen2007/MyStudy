思路一直接遍历当遇到空格时替换为%20
```
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        res=""
        for i in s:
            if i==" ":
                res+="%20"
            else:
                res+=i
        return res
```
思路二直接利用库函数解题
```
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        return s.replace(" ","%20")
```
![image.png](https://pic.leetcode-cn.com/93260ac388866370f041181b1defbbe0ca79dc539f7116457b9290e5380ca13b-image.png)

