其实就是分了两种情况：
纯数字
科学计数法（带e）：检测e的左右两边是否是纯数字，如果是纯数字检测右边数字中不带`.` ，带的话就返回False, 不带的话返回True
注意纯数字头尾都可以是小数点，只能是e不能是E，科学计数法(a×10^N)的a原来不需要是[0,10]范围内的。
代码如下:
```
class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0:
            return False
        if len(s) == 1:
            return s.isdigit()
        i = 0
        '''注意一定要去掉开头和结尾的空格'''
        while s[i] == ' ':
            i += 1
        j = len(s)-1
        while j>=0 and s[j] == ' ':
            j -= 1
        s = s[i: j+1]
        def is_pure_num(s):
            if len(s) == 0:
                return False
            if s[0] in '+-':
                s = s[1:len(s)]
            '''这个头头和尾尾都可以是.'''
            dotCount = 0
            for ch in s:
                if ch == '.':
                    if dotCount == 0:
                        dotCount = 1
                    else:
                        return False
                elif ch.isdigit():
                    continue
                else:
                    return False
            if len(s)==0 or( len(s) == 1 and dotCount == 1):
                return False
            return True
        if 'e' in s:
            for i in range(len(s)):
                if s[i] == 'e':
                    break
            if is_pure_num(s[0:i]) and is_pure_num(s[i+1:len(s)]):
                if '.' not in s[i+1:len(s)]:
                        return True
            return False
        else:
            return is_pure_num(s)
```
