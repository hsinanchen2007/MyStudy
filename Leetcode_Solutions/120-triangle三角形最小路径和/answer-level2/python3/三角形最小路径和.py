解题思路：
1）从上到下，计算每个数字位和上一行的相邻两个数字位的和，取最小和；以此类推，最后一行中最小和即为解；
2）第一列和最后一列有点特殊，它们只有一个选择；
![image.png](https://pic.leetcode-cn.com/d87687c5e6563dbfe90f16f2645cf3c56ee42c7d6948ceeab9983526a1599077-image.png)
3）其他位置，上一行相邻两个数，取最小的
![image.png](https://pic.leetcode-cn.com/8522b8fcc169386a6043aa8c71e21cb92be13721841bc5e545cbd1e82e279685-image.png)



代码如下：
```
class Solution:
    def minimumTotal(self, triangle: list) -> int:
        n = len(triangle)
        # 从第二行开始
        for i in range(1, n):
            # 处理列
            for j in range(i+1):
                # 第一列的没有选择，只能选上一行的第一列
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                # 最右的一列同样没得选，只能选上一行的最右一列
                elif j == i:
                    triangle[i][j] += triangle[i-1][j-1]
                # 其他列，可以选上一行相邻的两列，哪个小选哪个
                else:
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
        # 取最后一行，最小的和
        return min(triangle[n-1])
```
