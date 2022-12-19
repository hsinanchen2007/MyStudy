"+.e8" 	false
"1e" 	false
"0."	true
"-." 	false
".e1"	false
"+.8"	true
"."	false
给出上述几个具体的例子


下面是具体的代码, 主要是整理出这几种状态出来, 说实话, 有点不太容易整理出来

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        # 0. 普通整数
        # 1. 普通整数后面有个小数点
        # 2. 普通小数
        # 3. + / -号
        # 4. 一个整数或者小数后面有一个e
        # 5. 一个整整数和小数后面有一个e和 + / -号
        # 6. 一个整数或者小数后面有一个e和 0个或者1个(+/-)号以及>0个数字
        # 7. +/-. 或者 .
        # 8. 初始状态, 空字符串
        state = 8
        for c in s.strip():
            if '0' <= c <= '9':
                if state == 0:
                    state = 0
                elif state == 1:
                    state = 2
                elif state == 2:
                    state = 2
                elif state == 3:
                    state = 0
                elif state in [4, 5, 6]:
                    state = 6
                elif state == 7:
                    state = 2
                elif state == 8:
                    state = 0
            elif c in ['+', '-']:
                if state == 4:
                    state = 5
                elif state == 8:
                    state = 3
                else:
                    return False
            elif c == 'e':
                if state in [0, 1, 2]:
                    state = 4
                else:
                    return False
            elif c == '.':
                if state == 0:
                    state = 1
                elif state in [3, 8]:
                    state = 7
                else:
                    return False
            else:
                return False
        return state in [0, 1, 2, 6]

    def is_integer(self, s):
        if 'e' in s:
            return False
        elif '.' in s:
            return False
        elif len(s) == 0:
            return False
        else:
            if str.find(s, '-') >= 1:
                return False
            elif str.find(s, '+') >= 1:
                return False
            else:
                if '-' == s[0]:
                    s = s[1:]
                elif '+' == s[0]:
                    s = s[1:]
                if len(s) == 0:
                    return False
                for c in s:
                    if '0' <= c <= '9':
                        continue
                    else:
                        return False
                return True

    def is_decimal(self, s):
        if str.find(s, '.') == -1:
            return False
        else:
            part1 = s[:str.find(s, '.')]
            part2 = s[str.find(s, '.') + 1:]
            return (len(part1) == 0 or self.is_integer(part1) or part1 in ['-', '+']) \
                   and (len(part2) == 0 or self.is_integer(part2)) \
                   and (len(part1) != 0 or len(part2) != 0) \
                   and '-' not in part2 and '+' not in part2 \
                   and not (part1 in ['-', '+'] and len(part2) == 0)

    def isNumber2(self, s: str) -> bool:
        s = s.strip()
        if ' ' in s:
            return False
        if str.find(s, 'e') != -1:
            part1 = s[:str.find(s, 'e')]
            part2 = s[str.find(s, 'e') + 1:]

            return (self.is_integer(part1) or self.is_decimal(part1)) and (
                self.is_integer(part2)
            )
        else:
            if len(s) == 0:
                return False
            else:
                return self.is_integer(s) or self.is_decimal(s)
```


虽然这种直观上的题解(`isNumber2`)觉着看起来挺复杂, 但是实际上写起来还挺快的.好好体会`is_decimal`的return判断.