### 解题思路
感觉这个题的难点主要有两个：
- 1. 什么时候需要回溯，只有遇到“*”的时候才需要回溯，而且理解到，下一个star出现的时候更新回溯点就好。
- 2. 循环结束条件： 主串结束遍历，即可结束循环。这里面包含两种情况，主串结束模式串并未结束，此时不需回溯；主串未结束模式串已经结束，才需要回溯。

### 代码

```python3
# #  -*-  coding: utf-8  -*-

class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        sn = len(s)
        pn = len(p)
        si = 0
        pi = 0
        # 特殊情况
        if sn == 0 and pn == 0:
            return True
        if sn == 0 and all(x == '*' for x in p):
            return True
        if sn == 0 or pn == 0:
            return False


        flag = -1 # 回溯点
        back_s = -1


        # 模式串结束，但主串未结束的时候才需要回溯；
        # 主串结束，模式串并未结束的时候不需要回溯；
        # 所以循环的结束条件，可以是主串结束
        while si < sn:
            if pi >= pn:
                if flag != -1:
                    pi = flag + 1
                    si = back_s + 1
                    back_s = si
                else:
                    return False

            if pi >= pn:
                continue

            if s[si] == p[pi] or p[pi] == '?':
                si += 1
                pi += 1
            else:
                if p[pi] == '*':
                    flag = pi
                    back_s = si
                    pi += 1
                else:
                    if flag != -1:
                        pi = flag + 1
                        si = back_s + 1
                        back_s = si
                    else:
                        return False


        # 结束判断
        if si == sn and pi == pn:
            return True
        if si == sn:
            while pi < pn and p[pi] == '*':
                pi += 1
            if pi == pn:
                return True
            else:
                return False
        return False
```