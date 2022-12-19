# 思路
1. 首先定义字典roman_int_dict存储罗马字母对应的整数
2. 从第二个字母开始遍历字符串，存在两种情况：
    (1)当存在特殊情况时，则roman_int_dict[s[i]]>roman_int_dict[s[i-1]],此时应该减去roman_int_dict[s[i-1]]
    (2)否则，roman_int_dict[s[i]]<roman_int_dict[s[i-1]],此时应该加上roman_int_dict[s[i-1]]
3. 最后加上最后一个字母对应的整数即可,即roman_int_dict[s[-1]]
#代码
```
class Solution(object):
    def romanToInt(self, s):
        roman_int_dict = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        num = 0
        for i in range(1,len(s)):
            if roman_int_dict[s[i]]-roman_int_dict[s[i-1]]>0:
                num -=roman_int_dict[s[i-1]]
            else:
                num +=roman_int_dict[s[i-1]]
        num+=roman_int_dict[s[-1]]
        return num
```
