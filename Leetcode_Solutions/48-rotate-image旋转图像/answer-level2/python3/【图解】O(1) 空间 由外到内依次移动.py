### 解题思路
由外到内依次移动，每次之移动一个元素，所以空间复杂度是 O(1) 。

移动顺序是从左上角开始，每次开始移动一直要把对应的四个位置轮换一边才结束，再执行第二个位置。

一圈一圈的进行，比如最开始矩阵的大小是 5 × 5，第二轮则是 3 × 3，第三轮变为 1 × 1,每次都减 2。

第一轮移动：

1

![微信截图_20200130090729.png](https://pic.leetcode-cn.com/8680cf4f7ad9d2ac450ff391028ffb6952f92f23e63f34a1260eb67b8a214354-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130090729.png)


2

![微信截图_20200130091107.png](https://pic.leetcode-cn.com/c27a5cff89c37ec2f6e8bc8fcd60ce64fef35bf7b5fea612ea0acb07a41e5f7b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130091107.png)


3

![微信截图_20200130091225.png](https://pic.leetcode-cn.com/fac9e371badb2ab17643ba74911a819f10d2124d9d15a9d97ad2a71b2798e8e2-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130091225.png)


4

![微信截图_20200130091329.png](https://pic.leetcode-cn.com/076f642e245c5011667883680ec8efff31da597b52b3e5d56c0aa3894d4d4b92-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130091329.png)


第二轮移动：

1

![微信截图_20200130090903.png](https://pic.leetcode-cn.com/2aad0cd0f49f90885ec10a85f1df6578129e8c40e62a1f4dda3843f0fbb30e5a-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130090903.png)



2 - 4

![微信截图_20200130091751.png](https://pic.leetcode-cn.com/e77923a29cad984b1f704516d273845bb03e37ca1bc78c727ae2db3854221324-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200130091751.png)

求下一个位置的函数：

```python
def next_xy(x, y, s):
     return y, s - 1 - x
```

s 指当前矩阵的大小。

### 代码

```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def next_xy(x, y, s):
            return y, s - 1 - x
        n = len(matrix)
        i = 0
        for i in range(n):
            l = n - i * 2
            if l < 2: break
            for j in range(l-1):
                x, y = 0, j
                t = matrix[x+i][y+i]
                for k in range(4):
                    nx, ny = next_xy(x, y, l)
                    print(x, y, nx, ny)
                    print(t, matrix[nx+i][ny+i])
                    tt = matrix[nx+i][ny+i]
                    matrix[nx+i][ny+i] = t 
                    x, y, t = nx, ny, tt


```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)