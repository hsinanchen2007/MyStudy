
![image.png](https://pic.leetcode-cn.com/38cc2d56293202722607522cae9595d92949502b9577f9191f63445789e951ec-image.png)


```
'''
从叶子往根节点找反向路径，只要知道当前节点在所在层的偏移量
就可以算出父节点在上一层的偏移量，有偏移量就可以计算出父节点
的label
'''

from typing import List

class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        layer = 0
        for i in range(1, 33):
            if (1 << i) - 1 >= label:
                layer = i
                break

        cur = label
        ans = []
        while cur > 0:
            ans.append(cur)

            if layer % 2 == 1:
                offset = (cur - (1 << (layer - 1))) // 2
                layer -= 1
                cur = (1 << layer) - 1 - offset

            else:
                offset = ((1 << layer)-1 - cur) // 2
                layer -= 1
                cur = (1 << (layer - 1)) + offset

        ans.reverse()
        return ans
```
