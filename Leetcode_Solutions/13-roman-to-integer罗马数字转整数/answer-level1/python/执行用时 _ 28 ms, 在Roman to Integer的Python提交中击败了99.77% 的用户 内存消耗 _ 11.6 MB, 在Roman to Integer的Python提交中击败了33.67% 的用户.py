
创建一个字典，将阿拉伯数字与对应的整数一一对应存入字典中，然后检查输入的阿拉伯数字中是否有这六种情况，如果有则将输入的字符串中的特殊情况改成一个字母，返回修改后的字符串，查看字符串的每一个字符在字典中对应的值，将其相加得到最终结果。
代码如下：
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        sdt = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000,"a":4,"b":9,"c":40,"d":90,"e":400,"f":900}
        r = 0

        if "IV" in s:
            s = s.replace("IV","a")
        if "IX" in s:
            s = s.replace("IX","b")
        if "XL" in s:
            s = s.replace("XL","c")
        if "XC" in s:
            s = s.replace("XC","d")
        if "CD" in s:
            s = s.replace("CD","e")
        if "CM" in s:
            s = s.replace("CM","f")
        for i in s:
            if i in sdt:
                r += sdt[i]
        return r
