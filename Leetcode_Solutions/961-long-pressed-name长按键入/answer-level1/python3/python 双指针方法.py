class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i, l = 0, len(name)
        if name[0] != typed[0] or name[-1] != typed[-1]: return False
        for n in typed:
            if n == name[i]:
                if i < l - 1: 
                    i += 1
                else:
                    i = l - 1
            elif n != name[i] and n == name[i - 1]:
                continue
            else:
                return False
        return i == l - 1