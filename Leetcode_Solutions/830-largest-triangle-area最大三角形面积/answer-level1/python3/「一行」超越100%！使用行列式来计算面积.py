## 思路
+ 这道题给了坐标，那么明显用坐标面积公式要比海伦公式来得方便和精确。
+ 对于三角形的坐标面积公式来说，是这样的。
$$
S = \frac{1}{2}
\begin{vmatrix} x_1&y_1&1\\x_2&y_2&1\\x_3&y_3&1 \end{vmatrix}
$$
+ 我们可以利用 `numpy` 来计算行列式的值。
+ 利用 `combiniations` 来遍历所有点里任选三个点的所有组合。
+ 也可以将行列式按照最后一列展开后，再进行运算。

## 代码


+ 行列式
```python
from itertools import combinations
import numpy as np
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(abs(np.linalg.det(np.array([[x0,y0,1],[x1,y1,1],[x2,y2,1]]))) for (x0,y0),(x1,y1),(x2,y2) in combinations(points,3))/2
```

+ 如果对行列式进行一下展开和合并，那么可以得到这样的代码。
```python
from itertools import combinations
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(abs((x0-x2)*(y1-y2)-(x1-x2)*(y0-y2)) for (x0,y0),(x1,y1),(x2,y2) in combinations(points,3))/2
```
+ 这可以得到超过 100% 的速度。
![LeetCode-812.png](https://pic.leetcode-cn.com/65c57d1058e45c29d05bc97328f7f92882281182971395965c405d800b604591-LeetCode-812.png)