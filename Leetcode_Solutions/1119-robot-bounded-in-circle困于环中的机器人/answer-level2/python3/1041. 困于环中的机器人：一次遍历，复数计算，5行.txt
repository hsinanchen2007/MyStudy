一次遍历就够了，只用观察两个值，分别是位置`p`，和方向`d`，初始状态分别是`p = 0; d = 1`，左右旋转就是方向`d`分别乘复数`1j`和`-1j`，前进就位置`p`加上一个方向`d`。

一次遍历结束后，观察位置和方向：如果位置没变那肯定走不出去；如果位置变了，方向也变了，那必然会在多次循环后走回原点。

程序里具体用到了`bool`类型的数值化，比`if elif else`的判断略快一点。

时间复杂度$O(N)$，空间复杂度$O(1)$。

![image.png](https://pic.leetcode-cn.com/90b96d861ef637e2f00be98bb62ae595fdd414f4f5204a142122aa6f99b50516-image.png)

36ms仅供参考。

```python []
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        p, d = 0, 1
        for i in instructions:
            d *= (i == 'G') + 1j * ((i == 'L') - (i == 'R'))
            p += d * (i == 'G')
        return p == 0 or d != 1
```
