# 方法一：投机取巧法
用float(str)方法将字符串转成float，如果抛出异常 返回False
```
    def isNumber(self, s: str) -> bool:
        try:
            float(s) 
            return True
        except:
            return False
```
# 方法二：DFA(有限状态机)
本题状态转化很多，如果单纯用逻辑控制语句会疯掉。使用DFA(FSM)，定义好状态图。逻辑会清晰很多。
附上代码（参考自提交记录）：
```
    def isNumber(self, s: str) -> bool:
        s=s.strip()
        state = 0
        s = list(s)
        for i in s:
            if state == 0:
                if i == '.':state = 8
                elif '0'<=i<='9':state = 1
                elif i == '+' or i == '-':state = 7
                else: return False
            elif state == 1:
                if '0'<=i<='9':state = 1
                elif i == 'e' or i == 'E':state = 4
                elif i == '.':state = 2
                else:return False
            elif state == 2:
                if '0'<=i<='9':state = 3
                elif i == 'e' or i == 'E':state = 4
                else: return False
            elif state == 3:
                if '0'<=i<='9':state = 3
                elif i == 'e' or i == 'E': state = 4
                else:return False
            elif state == 4:
                if '0'<=i<='9':state = 6
                elif i == '+' or i == '-':state = 5
                else:return False
            elif state == 5:
                if '0'<=i<='9':state = 6
                else: return False
            elif state == 6:
                if '0'<=i<='9':state = 6
                else: return False
            elif state == 7:
                if '0'<=i<='9':state = 1
                elif i == '.':state=8
                else:return False
            elif state == 8:
                if '0'<=i<='9':state = 3
                else: return False
        return state in [1,2,3,6]
```
# 方法三：正则表达式
能用有限状态机解决肯定能正则匹配(等价)
```
def isNumber(self, s: str) -> bool:
    return re.match(r' *[-+]?(?:(?:[0-9]+\.?[0-9]*)|(?:\.[0-9]+))(?:e[-+]?[0-9]+)? *$',s,re.I)
```





