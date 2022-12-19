### 解题思路
因为是四个方向可任意移动，所以到达目标的时间即为两点间的曼哈顿距离，当"我"到目标点距离小于所有阻碍者到目标点距离时，可以成功逃脱。

注：[数学中的各种距离含义](https://blog.csdn.net/Losteng/article/details/50893931)

### 代码

```python3
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        return all([abs(target[0])+abs(target[1]) < abs(ghost[0]-target[0])+abs(ghost[1]-target[1]) for ghost in ghosts])
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)