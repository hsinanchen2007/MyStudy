执行用时 :44 ms
解题思路：把s逐个字母匹配到t里面去，一旦匹配上
就用index把第一个匹配上的字母之前的字符全部去掉
然后进行下一个字母的匹配，直到结束

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for s1 in s:
            if s1 in t:
                t = t[t.index(s1)+1:]
            else:
                return False
        else:
            return True