```
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if len(s) == 0:
            return False
        ss = []
        temps = s.split('e')
        for temp in temps:
            ss.extend(temp.split('E'))

        if len(ss) == 1:
            if len(ss[0]) == 0:
                return False
            ss = ss[0]
            if ss[0] == '+' or ss[0] == '-':
                ss = ss[1:]
            if '+' in ss or '-' in ss:
                return False
            strs = "".join(ss).split('.')
            if len(strs) == 1:
                if len(strs[0]) == 0:
                    return False
                for num in strs[0]:
                    if ord(num) <48 or ord(num)>57:
                        return False
                return True
            elif len(strs) == 2:
                if len(strs[0]) == 0 and len(strs[1]) == 0:
                    return False
                for num in strs[0]:
                    if ord(num) <48 or ord(num)>57:
                        return False
                for num in strs[1]:
                    if ord(num) <48 or ord(num)>57:
                        return False
                return True
            else:
                return False

        elif len(ss) == 2:
            if len(ss[0]) == 0 or len(ss[1]) == 0:
                return False
            front = ss[0]
            back = ss[1]
            if '.' in back or '-' in back[1:] or '+' in back[1:]:
                return False

            if front[0] == '+' or front[0] == '-':
                front = front[1:]
            if '+' in front or '-' in front:
                return False
            strs = "".join(front).split('.')
            if len(strs) == 1:
                if len(strs[0]) == 0:
                    return False
                for num in strs[0]:
                    if ord(num) <48 or ord(num)>57:
                        return False
            elif len(strs) == 2:
                if len(strs[0]) == 0 and len(strs[1]) == 0:
                    return False
                for num in strs[0]:
                    if ord(num) <48 or ord(num)>57:
                        return False
                for num in strs[1]:
                    if ord(num) <48 or ord(num)>57:
                        return False
            else:
                return False

            if back[0] == '+' or back[0] == '-':
                back = back[1:]
            if len(back) == 0:
                return False
            for num in back:
                if ord(num) <48 or ord(num)>57:
                    return False
            return True
        else:
            return False
```
