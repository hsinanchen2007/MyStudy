### 解题思路
简单容易理解，代码长了点，但是很好理解
用时击败90%左右
我想的核心就是，`总的贡献面积-重叠部分面积`
最困惑的就是重叠面积怎么算？

重叠面积无非是两种情况：
1. 自身重叠面积
2. 相邻重叠面积

`[[2]]` 这个重叠面积就是`自身重叠`，`(2-1)*2)` 面积为 `2 * 6 - 2 = 10`
`[[1,1]]` 这个重叠面就是`相邻重叠`
`[[1,2]]` 自身重叠+相邻重叠

问题又来了，左右相邻的固然好求，但是上下相邻怎么求

可以使用`矩阵旋转`，这个矩阵旋转前面专门有一个这样的题

在Python中可以使用`zip()`进行快捷操作

`[[1,2][3,4]]` 使用 `list(*zip(grid))` 可以得到 `[[1,3][2,4]]`

转置之后，再进行一次上面的操作就可以了

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        sum_surface = 0 # 所有立方贡献的总面积
        sum_sub = 0 # 重叠部分的总面积
        temp = 0 # 用于临时记录上一个位置的立方个数

        for row_list in grid:
            for v in row_list:
                sum_surface += v*6
                if v >= 1:
                    # 自身重叠应该减去的面积
                    sum_sub += (v-1)*2

                    # 相邻重叠应该减去的面积
                    if v > temp:
                        sum_sub += temp * 2
                    else:
                        sum_sub += v*2
                temp = v
            # 内层循环结束，进入下一行，将temp置0
            temp=0

        # 旋转矩阵
        grid = list(zip(*grid))
        for row_list in grid:
            # 第一行
            for v in row_list:
                # sum_surface += v
                if v >= 1:
                    # 自身重叠面积已经减去过了，这里就不减了
                    # sum_sub += (v-1)*2

                    # 相邻重叠应该减去的面积
                    if v > temp:
                        sum_sub += temp * 2
                    else:
                        sum_sub += v*2
                # 用于临时保存数字，方便下一次做比较
                temp = v
            temp=0
        return sum_surface - sum_sub

```