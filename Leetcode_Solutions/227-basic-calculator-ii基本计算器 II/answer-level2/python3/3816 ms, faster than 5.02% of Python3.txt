思路就是用栈
乘除法直接算, 结果存栈
其他的都直接入栈, 最后再遍历一按顺序计算, 因为此时只剩加减法了, 运算顺序就无所谓了
```
class Solution:
    def calculate(self, s: str) -> int:
        stack, nums = [], set(['0','1','2','3','4','5','6','7','8','9', ' '])
        l, i = len(s), 0
        while i<l:
            tmp = 0
            if s[i] in nums:
                while i<l and s[i] in nums: # 代码重复太厉害, 好好学学下面的!
                    if s[i]==' ': 
                        i += 1
                        continue
                    tmp = tmp*10 + int(s[i])
                    i += 1
                stack.append(tmp)
                continue
            elif s[i]=='*':
                while i+1<l and s[i+1] in nums:
                    if s[i+1]==' ': 
                        i += 1
                        continue
                    tmp = 10*tmp + int(s[i+1])
                    i += 1
                stack.append(stack.pop()*tmp)
            elif s[i]=='/':
                while i+1<l and s[i+1] in nums:
                    if s[i+1]==' ': 
                        i += 1
                        continue
                    tmp = 10*tmp + int(s[i+1])
                    i += 1
                stack.append(stack.pop()//tmp)
            elif s[i] in {'+', '-'}:
                stack.append(s[i])
            i += 1
        res = stack.pop(0)        
        while stack:
            op = stack.pop(0)
            if op=='+':
                res += stack.pop(0)
            elif op=='-':
                res -= stack.pop(0)
        return res
```

学习一个只有50ms的代码, 把每个数和它前面的符号连起来
很简洁快速
```
class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        last_symbol = "+"
        num_str = ""
        s = s.strip()
        for ch in s: # this changes 5%->99%
            if ch in '-+*/':
                num = int(num_str)
                if last_symbol is '+': # last_symbol代表了当前数前面的op
                    stack.append(num)
                elif last_symbol is '-':
                    stack.append(-num)
                elif last_symbol is '*':
                    stack[-1] *= num
                else:
                    stack[-1] = int(stack[-1]/num)
                num_str = ""
                last_symbol = ch
            else:
                num_str += ch
        num = int(num_str)
        if last_symbol is '+':
            stack.append(num)
        elif last_symbol is '-':
            stack.append(-num)
        elif last_symbol is '*':
            stack[-1] *= num
        else:
            stack[-1] = int(stack[-1]/num)
        return sum(stack)
```