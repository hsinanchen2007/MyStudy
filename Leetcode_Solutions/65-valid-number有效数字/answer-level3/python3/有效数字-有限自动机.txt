使用有限状态机即可，由于有限状态机永远不变，所以可以将状态转移矩阵定义为类属性以提高效率。

有限状态机如下：
![image.png](https://pic.leetcode-cn.com/716afb809006b3214ba011db214683a39d236cac573729fdb5f7a861f2c1983d-image.png)

其中，状态2，3，4，6可以视为终态

遍历字符串，若进入死状态，返回False

遍历结束以后，如果最终状态为终态，返回True，否则返回False

```
```python3
class Solution:
    states= [[-1 for i in range(256)] for j in range(9)]
    states = [[-1 for i in range(256)] for j in range(9)]
    states[0][ord('0'):ord('9')] = [2 for i in range(10)]
    states[0][ord('+')] = 1
    states[0][ord('-')] = 1
    states[0][ord('.')] = 8
    states[1][ord('0'):ord('9')] = [2 for i in range(10)]
    states[1][ord('.')] = 8
    states[2][ord('0'):ord('9')] = [2 for i in range(10)]
    states[2][ord('.')] = 3
    states[2][ord('e')] = 5
    states[3][ord('0'):ord('9')] = [4 for i in range(10)]
    states[3][ord('e')] = 5
    states[4][ord('0'):ord('9')] = [4 for i in range(10)]
    states[4][ord('e')] = 5
    states[5][ord('0'):ord('9')] = [6 for i in range(10)]
    states[5][ord('+')] = 7
    states[5][ord('-')] = 7
    states[6][ord('0'):ord('9')] = [6 for i in range(10)]
    states[7][ord('0'):ord('9')] = [6 for i in range(10)]
    states[8][ord('0'):ord('9')] = [4 for i in range(10)]
    m = {
            0: False,
            1: False,
            2: True,
            3: True,
            4: True,
            5: False,
            6: True,
            7: False,
            8: False
        }
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        cur = 0
        for c in s:
            cur = self.states[cur][ord(c)]
            if cur == -1:
                return False
        return self.m[cur]
```

