数字就进栈，遇到'C'就出栈，遇到'D'就先出栈，然后乘以二再将两个数字都进栈，遇到'+'就把最上面的两个出栈，相加之后得到一个新的数字，将三个按顺序再进栈，最后计算栈内所有数字相加结果

```
def calPoints(self, ops: List[str]) -> int:

        l = []
        sum = 0
        for s in ops:
            if s == '+':
                l_top = l.pop()
                s_top = l.pop()
                new_ele = l_top + s_top
                l.append(s_top)
                l.append(l_top)
                l.append(new_ele)
            elif s == 'C':
                l.pop()
            elif s == 'D':
                top = l.pop()
                new_ele = 2 * top
                l.append(top)
                l.append(new_ele)
            else:
                l.append(int(s))
        for n in l:
            sum = sum + n
        return sum

```
