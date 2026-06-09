括号匹配用栈就对了。
```
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i in s:
            if i != ']':                          #如果字符不是']'就入栈
                stack.append(i)
            else:                                 #字符是']'就开始往前匹配
                tmp = ''
                j = len(stack) - 1
                while j > 0:                      #寻找待扩倍的子字符串
                    if stack[j] == '[':
                        break
                    else:
                        tmp = stack[j] + tmp
                        j -= 1
                num = ''
                j -= 1
                while j >= 0:                     #寻找子字符串的倍数
                    if stack[j].isnumeric():
                        num = stack[j] + num
                        j -= 1
                    else:
                        break
                s = tmp*int(num)
                stack = stack[:j+1] + [s]
        return ''.join(stack)
```
