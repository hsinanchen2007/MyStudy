## 解题思路
这是一道很有意思的题目，我们只需要计算一个点对应的互补位置，我称它为互补点，如NxN的矩阵，给定一个点是`(x, y)`，那么它的互补点就是`(x1, y1) = (N-x, N-y)`，然后以矩阵中心为旋转点，我们可以计算出给定点`(x, y)`的对应旋转关系为：`(x, y) -> (y, x1) -> (x1, y1) -> (y1, x) -> (x, y)`
这么说很抽象，我们可以通过编写程序输出旋转后的矩阵各点对应位置：
![](https://pic.leetcode-cn.com/587a6d20e579e2fe144c263313423486cabefac8fe63fc2a8f8ce6e3d55a6862.png)
这样，我们就可以很简单地对矩阵进行旋转了。
需要注意的是，在旋转的时候，我们对行的遍历只需要遍历一半，对列的遍历需要不断往中间收缩，避免重复旋转。

## 代码
```python3
class Solution:
    def rotate(self, m: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(m) - 1
        c_beg = 0
        c_end = N
        for row in range(N // 2 + 1):
            for col in range(c_beg, c_end):
                r, c = N - row, N - col
                m[row][col], m[col][r], m[r][c], m[c][row] =\
                    m[c][row], m[row][col], m[col][r], m[r][c]
            c_beg += 1
            c_end -= 1

```

## 运行结果：
[无效的图片地址](http://blog.stublockchain.com/usr/uploads/2020/04/2880874864.png)

