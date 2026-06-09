### 解题思路
(1)单个坐标堆放的立方体v个，形成的柱体（类似）的表面积，即为6*v - 2*(v-1)
总主体表面积（未去除相邻重复）代码块：
![image.png](https://pic.leetcode-cn.com/8262f903c7a5067d1a85a15780917a298fffa62a66c7629e65dd243b67a9ae6c-image.png)


(2)贴在一起的表面积 = 相邻两个柱体中，矮的柱体立方体数量v*2

1)此部分划分为两个部分：可先遍历行重复表面积，再遍历列重复表面积。可借用zip()函数逆转坐标矩阵，即为列变为行，也就是做两次遍历行重复表面积，用同一种代码块，例如
>>> a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
>>> list(zip(*a))
[(1, 4, 7), (2, 5, 8), (3, 6, 9)]

2)遍历行重复表面积代码块：
![image.png](https://pic.leetcode-cn.com/65860767e1461c57ba49494549ba89494bc286622c4dbd6a5618c6848d7b6bcb-image.png)

(3) 结果= 1) - 2)
(4)关于逆转矩阵
zip()函数输出是元组，应转为列表
具体用法参考：
https://blog.csdn.net/zhu_liangwei/article/details/7967237?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
也可直接程序逆转——Python列表推导
print [ [row[col] for row in a] for col in range(len(a[0]))]

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        def Original_Sur(grid: List[List[int]]):
            sur_num = 0
            for i in range(len(grid)):
                for j in range(len(grid[i])):
                    v = grid[i][j]
                    if v == 0:
                        continue
                    else:
                        sur_num += 6*v -2*(v - 1)
            return sur_num
        def sub_Sur(grid: List[List[int]]):
            def sub_part(grid: List[List[int]]):
                sub_sur = 0
                for single in grid:
                    if len(single) <= 1:
                        continue
                    else:
                        cell_num = single[0]
                        for h in single[1:]:
                            if h < cell_num:
                                cell_num = h
                                sub_sur += 2*cell_num
                            else:
                                sub_sur += 2*cell_num
                                cell_num = h
                return sub_sur
            grid_part = list(zip(*grid))
            sub_sur = sub_part(grid) + sub_part(grid_part)
            return sub_sur
        total_sur = Original_Sur(grid) - sub_Sur(grid)
        return total_sur
```