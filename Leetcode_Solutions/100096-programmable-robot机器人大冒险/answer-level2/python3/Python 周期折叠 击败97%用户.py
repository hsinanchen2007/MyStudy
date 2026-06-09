![image.png](https://pic.leetcode-cn.com/2c33b299709c8762a4068f78583107bb1715ccf2ae52eb359691a1f927a3ee0e-image.png)


```
'''
由于每个周期的运动是重复的，因此可以把终点和障碍点的坐标全部投射
回第一个周期可能出现的坐标范围内，可以快速判断是否有冲突出现
'''


from typing import List
class Solution:

    def getReflectioin(self, i, j, i_circle, j_circle):
        num = i // i_circle
        ii, jj = i - i_circle * num , j - j_circle * num
        if ii == 0 and jj < 0:
            ii, jj = ii + i_circle, jj + j_circle
        return (ii, jj)

    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        pos = {(0, 0)}     # 第一个周期中可能出现的所有点

        i, j = 0, 0
        for ch in command:
            if ch == 'U':
                i += 1
            else:
                j += 1
            pos.add((i, j))

        i_circle, j_circle = i, j

        # 检查终点根据周期折叠后会不会出现在可能的点中
        if self.getReflectioin(y, x, i_circle, j_circle) not in pos:
            return False

        for j, i in obstacles:
            if i <= y and j <= x and self.getReflectioin(i, j, i_circle, j_circle) in pos:
                return False
        return True
```
