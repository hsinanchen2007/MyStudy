```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        # 感觉用堆栈很容易能解决。
        # ??题没看懂

        if not seq:
            return []

        stack_a = 0
        stack_b = 0
        flag = [] # 用于区分上一个括号写进哪个堆了。
        ret = []

        for item in seq:
            if item == "(":
                if stack_a <= stack_b:
                    ret.append(0)
                    stack_a += 1
                    flag.append(1)
                else:
                    ret.append(1)
                    stack_b += 1
                    flag.append(0)
            else:
                if flag.pop():
                    ret.append(0)
                    stack_a -= 1
                else:
                    ret.append(1)
                    stack_b -= 1
        return ret
```
