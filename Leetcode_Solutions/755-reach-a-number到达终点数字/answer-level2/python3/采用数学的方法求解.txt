执行用时 :
44 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :
12.9 MB, 在所有 Python3 提交中击败了100.00%的用户

1. 首先注意到对称性，向正向行走和反向行走相同距离使用最小步数是一样的，因此只考虑target>0的情况。
2. 注意到，走n步所能达到的最大距离为`n * (n + 1) / 2`。
因此，令`a = math.sqrt(2 * target + 0.25) - 0.5`，若`a == int(a)`则说明此时的target正好是a步所能达到的最远距离。直接返回int(a)即可。
3. 如果`a != int(a)`，则将a设置为最远距离大于target的最小步数。此时分情况讨论。
4. 注意到对于走了步数n：
 + 若`((n + 1) // 2) % 2 == 1`则此时停下来的距离肯定为奇数
 + 若`((n + 1) // 2) % 2 == 0`则此时停下来的距离肯定为偶数
 + 若步数a对应的奇偶数情况和target正好相同，则输出a。
 + 若步数a对应的奇偶数情况和target不相同，则输出大于a的下一个与target奇偶相同的步数。
5. 直接看代码更清晰
```
import math


class Solution:
    def reachNumber(self, target: int) -> int:
        if target < 0:
            target = 0 - target
        a = math.sqrt(2 * target + 0.25) - 0.5
        # print(a)
        if a == int(a):
            return int(a)
        else:
            a = int(a) + 1
            if ((a + 1) // 2) % 2 == target % 2:
                return a
            elif a % 2 == 1:
                return a + 2
            else:
                return a + 1
```
