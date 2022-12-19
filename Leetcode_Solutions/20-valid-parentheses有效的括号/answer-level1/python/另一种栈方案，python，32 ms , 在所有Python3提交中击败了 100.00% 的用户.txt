```
class Solution:
    def isValid(self, s: str) -> bool:
        #if len(s) % 2 != 0: #在系统的测试用例中加入长度判断并没有显著提高速度
        #    return False
        dic = { #来啊，配对啊
            '(':')',
            '[':']',
            '{':'}'
        }
        stack = [] #搞个栈
        for sym in s:
            if sym in dic: #左括号肯定没错，统统入栈
                stack.append(sym)
            else:
                if stack and dic[stack[-1]] == sym: #如果栈非空（意味着至少里面有一个左括号），且配上对了
                    stack.pop() #，就弹掉栈里被配对的最后一个左括号
                else:
                    return False #除此以外都是魂淡
        return not stack #过关斩将还是空的则意味着全部配对上了！
```