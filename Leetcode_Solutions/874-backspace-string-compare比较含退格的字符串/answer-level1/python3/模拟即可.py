```
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        a=self.function1(S)
        b=self.function1(T)
        return a==b

    def function1(self, s):
        s_list = list(s)
        while True:
            tmp="".join(s_list)
            pos = tmp.find("#")
            if pos == -1:
                break
            if pos == 0:
                s_list.pop(pos)
            else:
                s_list.pop(pos)
                while pos:
                    pos -= 1
                    if s_list[pos] != "#":
                        s_list.pop(pos)
                        break
        return s_list
```