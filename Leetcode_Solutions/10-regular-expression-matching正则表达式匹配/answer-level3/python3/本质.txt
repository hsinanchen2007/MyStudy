这个题目我是真的没有思路，纠结的点主要在于
example:
s: aaa
p: ab`*`a`*`c`*`a
看不透本质吧，如果回溯不知道如何回溯。
参考了官方公布的代码，写写我的理解吧。
1.匹配s字符串和p字符串的第一个字符
2.当p字符串的第二个字符是`*`时，有两种模式。
  2.1 no matter 第一个字符是否匹配，*默认为前面的字符0次，这样就用s字符串和去掉前两个字符的p字符串比较。
  2.2 第一个字符串匹配 and 去掉前1个字符的s字符串和p字符串匹配，因为p字符串的第一个字符在后面的匹配中还可能使用。
3.当p字符串的第二个字符不是`*`时，第一个字符串匹配 and 去掉第一个字符的s字符串和去掉第一个字符的p字符串匹配。

递归结束条件是p字符串为空，因为p字符串只要还有就还有希望匹配成功，另外p字符串如果结束了匹配也就结束了，哪怕s字符串没结束，已经有答案了。
首字符匹配中考虑到s字符串可能没空，就无法匹配。
我感觉还是蛮难的，至少对我向来直向式的思维模式是很大的挑战。
但是呢，这个代码只超过了5%的python用户，大神很多啊，改天膜拜一下。
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(p) == 0 :
            return bool(len(s) == 0)
        first_match = ( len(s) != 0 and (s[0] == p[0] or p[0] == '.') )

        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s,p[2:] if len(p)>=3 else "") or (first_match and self.isMatch(s[1:] if len(s)>=2 else "",p))
        else:
            return first_match and self.isMatch(s[1:] if len(s)>=2 else "",p[1:])
```
