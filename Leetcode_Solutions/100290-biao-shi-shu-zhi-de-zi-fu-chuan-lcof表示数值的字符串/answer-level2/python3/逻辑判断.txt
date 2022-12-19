```
class Solution:
    """
    底数可以是小数,指数不能是小数
    底数和指数前可以有+-，都不能为空
    小数点左右不能同时为空
    """
    def isNumber(self, s: str) -> bool:
        print(''.isdigit())
        s = s.strip().lower()
        pos_e = s.find('e')
        if pos_e == -1: # 没 e ，判断 s 是不是底数
            return self.isdi(s)
        else:
            return self.isdi(s[:pos_e]) and self.iszhi(s[pos_e+1:])

    def isdi(self, s): # 判断是不是底数
        if not s:      # 判空
            return False
        if s[0] in '+-': # 去掉+-号
            s = s[1:]
        pos_d = s.find('.')
        if pos_d == -1:  # 是整数
            return s.isdigit()
        else:               # 左右不能同时为空, 且不空的是数字
            if not s[:pos_d]:
                return s[pos_d+1:].isdigit()
            if not s[pos_d+1:]:
                return s[:pos_d].isdigit()
            return s[:pos_d].isdigit() and s[pos_d+1:].isdigit()

    def iszhi(self, s): # 判断是不是指数
        if not s:
            return False
        if s[0] in '+-':
            s = s[1:]
        return s.isdigit()
```