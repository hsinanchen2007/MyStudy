贪心策略: 每次追加'a', 'b', 'c'中剩余数量最多的字符, 并记录上次添加的字符是哪种, 从而使得不会有连续的3个'a', 'b'或'c'出现, 同时保证串最长.
即: 追加过程循环进行, 直到串的长度不再增长为止
时间复杂度O(n), 空间复杂度O(1)。
```
class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        lastCh, isAdd = "x", 1
        res = ""
        while isAdd:
            isAdd = 0
            if a >= b >= c or a >= c >= b:
                if lastCh != "a":
                    if a >= 2:
                        res += "aa"; a -= 2
                    elif a == 1:
                        res += "a"; a -= 1
                    lastCh = "a"; isAdd = 1
                else:
                    if b >= c and b >= 1:
                        res += "b"; lastCh = "b"; b -= 1; isAdd = 1
                    elif c >= b and c >= 1:
                        res += "c"; lastCh = "c"; c -= 1; isAdd = 1
            elif b >= a >= c or b >= c >= a:
                if lastCh != "b":
                    if b >= 2:
                        res += "bb"; b -= 2
                    elif b == 1:
                        res += "b"; b -= 1
                    lastCh = "b"; isAdd = 1
                else:
                    if a >= c and a >= 1:
                        res += "a"; lastCh = "a"; a -= 1; isAdd = 1
                    elif c >= a and c >= 1:
                        res += "c"; lastCh = "c"; c -= 1; isAdd = 1
            elif c >= a >= b or c >= b >= a:
                if lastCh != "c":
                    if c >= 2:
                        res += "cc"; c -= 2
                    elif c == 1:
                        res += "c"; c -= 1
                    lastCh = "c"; isAdd = 1
                else:
                    if a >= b and a >= 1:
                        res += "a"; lastCh = "a"; a -= 1; isAdd = 1
                    elif b >= a and b >= 1:
                        res += "b"; lastCh = "b"; b -= 1; isAdd = 1
        return res
```
