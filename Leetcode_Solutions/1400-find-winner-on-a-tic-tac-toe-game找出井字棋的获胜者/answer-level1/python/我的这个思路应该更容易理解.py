![QQ截图20200104195235.png](https://pic.leetcode-cn.com/99651df9e8e62cf276ec28ba380d02c107d314baef942d120539c3034fa3d375-QQ%E6%88%AA%E5%9B%BE20200104195235.png)

### 解题思路

1、A,B分别抽出来作为一个数组
2、从A里面随机取三个看是否为直线，为直线则A赢。从B里面随机取三个看是否为直线，为直线则B赢
3、A和B都没有赢，看是否还有空格

### 代码

```python
from itertools import permutations
class Solution(object):
    def tictactoe(self, moves):
        """
        :type moves: List[List[int]]
        :rtype: str
        """
        A = moves[::2]
        B = moves[1::2]
        for a,b,c in itertools.permutations(A, 3):
            if (b[1] - a[1])*(c[0] - a[0]) == (c[1] - a[1])*(b[0] - a[0]):
                return "A"
        for a,b,c in itertools.permutations(B, 3):
            if (b[1] - a[1])*(c[0] - a[0]) == (c[1] - a[1])*(b[0] - a[0]):
                return "B"
        
        if len(A) + len(B) == 9:
            return "Draw"
        else:
            return "Pending"


```