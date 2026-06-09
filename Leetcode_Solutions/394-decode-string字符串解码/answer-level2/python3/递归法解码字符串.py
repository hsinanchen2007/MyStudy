# 基本思路
这道题目适合用递归的方法.
递归方式具体如下:
1. 从头开始遍历字符串,遇到非数字,则跳到下个字符,并把这个字符直接加入到结果中
2. 如果遇到数字,则把数字覆盖的子串找出来,数字乘以子串后继续遍历.

# 技巧  
技巧主要是找数字覆盖的子串,由于字符串是well-formed,所以我们只要根据开括号和闭括号就可以找出来了
代码中通过self.find_bracket_coverage方法实现

# 需要注意的点
因为数字可能是多位数,所以遍历字符串遇到数字时,需要接着找,直到遇到非数字.
代码中通过self.find_digits方法实现

# 效果
时间上击败了95%的用户
内存消耗上击败了5%的用户


```
class Solution:
    
    @staticmethod
    def find_bracket_coverage(s: list):
        """find the substring contained in the first bracket associated to the preceding digit of s
        and alter the input string
        """
        try:
            assert s[0] == "["
        except AssertionError:
            raise AssertionError("数字后面竟然不是[")
        inside = []
        
        # cnt assigns the number of open brackets
        cnt = 1
        s.pop(0)
        
        # find the whole substring inside the first bracket
        while cnt > 0:
            if s[0] == "[":
                cnt += 1
            elif s[0] == "]":
                cnt -= 1
            inside.append(s.pop(0))
        inside.pop(-1)
        return "".join(inside)
        
    @staticmethod
    def find_digits(s: str):
        """since the integer could be multi-digit we need to find all digits 
        """
        digit = []
        while s[0].isdecimal():
            digit.append(s.pop(0))
        return int("".join(digit))
        
        
    def decodeString(self, s: str) -> str:
        if not s:
            return ""
        else:
            res = ""
            s = list(s)
            while s:
                char_tmp = s[0]
                if not char_tmp.isdecimal():
                    res += char_tmp
                    s.pop(0)
                else:
                    times = self.find_digits(s)
                    inside = self.find_bracket_coverage(s)
                    res += times * self.decodeString(inside)
            return res
```
