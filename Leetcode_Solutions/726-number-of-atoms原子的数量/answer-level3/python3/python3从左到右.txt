我是从左到右写的，利用堆栈保存现场。
```
from collections import defaultdict
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        stack = []
        n = len(formula)
        i = 0
        temp = defaultdict(int)
        while i < n:
            #遇到左括号将temp压入堆栈
            if formula[i] == '(':
                stack.append(temp)
                temp = defaultdict(int)
            #遇到数字将之前的原子翻倍
            elif formula[i].isdigit():
                repeat = str(formula[i]) #计算需要翻倍多少次
                while i+1<n and formula[i+1].isdigit():
                    i = i + 1
                    repeat = repeat + formula[i]
                temp[Atom] = temp[Atom] + int(repeat) - 1 #翻倍
            #遇到右括号，将括号内容翻倍，加上从括号中pop出来的字典
            elif formula[i] == ')':
                if i+1<=n-1 and formula[i+1].isdigit():
                    i = i + 1
                    repeat = formula[i]
                    while i+1 < n and formula[i+1].isdigit():
                        i = i + 1
                        repeat = repeat + formula[i]
                    for atom in temp:
                        temp[atom] *= int(repeat)
                p = stack.pop()
                for atom in p:
                    temp[atom] += p[atom]
            #遇到了一个原子
            elif formula[i].isupper():
                Atom = formula[i]
                if i + 1<=n - 1 and formula[i+1].islower():
                    i = i + 1
                    Atom = Atom + formula[i]
                temp[Atom] = temp[Atom] + 1
            i += 1
        #按照字典顺序改成字符串
        ans = ""
        for atom in sorted(temp):
            if temp[atom] == 1:
                ans = ans + atom
            else:
                ans = ans + atom + str(temp[atom])
        return ans
```
