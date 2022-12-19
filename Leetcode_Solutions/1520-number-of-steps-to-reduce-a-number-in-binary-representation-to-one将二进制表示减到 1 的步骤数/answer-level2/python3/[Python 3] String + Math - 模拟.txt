更正题解: 
法一 - 字符串转10进制数, 然后模拟即可。时间复杂度O(n), 空间复杂度O(1)。
不过需要注意给定串s最大长度可达500, 直接操作并不可取, 语言不通用! 
```
class Solution:
    def numSteps(self, s: str) -> int:
        num, val, res = 0, 1, 0
        for i in range(len(s) - 1, -1, -1):
            num += (ord(s[i]) - 48) * val
            val *= 2
        # print(num)
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            res += 1
        return res
```

法二: 模拟
字符串->字符数组, 然后自右向左遍历, 若当前位为0则继续考察前一位, 当前位为1则模拟从低位向高位的进位, 直到发现某个数位为'0', 将其进1置'1'.
时间复杂度O(n), 空间复杂度O(n). 
```
class Solution:
    def numSteps(self, s: str) -> int:
        s = list(s)
        curIdx, res = len(s) - 1, 0
        while curIdx > 0:
            if s[curIdx] == '0':
                curIdx -= 1; res += 1
            else:
                res += 1
                while curIdx >= 0 and s[curIdx] == '1':
                    curIdx -= 1; res += 1
                if curIdx > 0:
                    s[curIdx] = '1'
        return res
```
