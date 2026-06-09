```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s.isspace() or len(s) == 1:
            return s
        newS = "#"
        for c in s:
            newS += c
            newS += "#"
        maxLen = 0
        res = ""
        for i in range(2, len(newS)):
            left = right = i
            length = 1
            while((left-1) >= 0 and (right+1) < len(newS)):
                if(newS[left-1] != newS[right+1]) : break
                else:
                    left -= 1
                    right += 1
                    length += 2
            if maxLen < length:
                maxLen = length
                res = newS[left:right+1]
            if len(newS)-i < maxLen/2 : break

        return res.translate(str.maketrans('', '', '#'))
```
对于中心扩展发，直接暴力地去遍历所有字母，从而找到最长回文串的方法，在一些细节的处理上很麻烦。比如串“aba”，与串“bb”在判断的时候就不好确定中心点。这里提供一种方案，很好理解滴（当然不是我想出来的，是很久以前从别人那看到的，忘了是哪位大佬了，嘿嘿） 对原字符串进行处理：即每个字符之间都加上一个‘#’， 如串“aba”经处理后就变成了“#a#b#a#”，“bb”->"#b#b#"，这样无论原串是奇数还是偶数，经处理后都变成奇数。 然后再用中心扩展法，计算处理后的串的最长回文串，得到的结果再将“#”去除，就是正确答案了，
