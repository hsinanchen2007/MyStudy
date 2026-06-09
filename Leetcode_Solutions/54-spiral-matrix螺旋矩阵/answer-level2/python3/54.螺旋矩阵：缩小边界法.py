我的解法还是比较直观的：

1. 在矩阵的四个角落分别指定四个边界指针，从左上角开始按顺时针依次定义他们为上边界`minY`、右边界`maxX`、下边界`maxY`、左边界`minX`，然后从第一个元素开始，设置一个大循环：
2. 向右收集，结束后缩小上边界（minY下移），检查已收集元素的个数是否等于总数（是否已经收集齐了全部的元素）
3. 向下收集，结束后缩小右边界（maxX左移），检查是否集齐
4. 向左收集，结束后缩小下边界（maxY上移），检查是否集齐
5. 向上收集，结束后缩小左边界（minX右移），检查是否集齐
6. 重复步骤2，当元素收集齐了，结束循环，返回结果

这里是配图：
![IMG_0411.jpg](https://pic.leetcode-cn.com/fda49b23c6b1ae7b509c793d6dc3ebba9fdfaafa481c283191b4836eb5371e90-IMG_0411.jpg)

源码：
```
class Solution:

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # 矩阵行数
        row = len(matrix)
        # 矩阵列数
        col = len(matrix[0]) if row > 0 else 0
        if row == 0 or col == 0:
            return []
        
        order = []
        # 已经收集的元素个数
        count = 0
        # 在矩阵中需要收集的全部元素数量
        total = row * col
        # 上边界
        minY = 0
        # 右边界
        maxX = col - 1
        # 下边界
        maxY = row - 1
        # 左边界
        minX = 0
        
        # 首先收集原点
        (x, y) = (0, 0)
        order.append(matrix[y][x])
        count += 1
        
        while True:
            # 向右收集
            while x < maxX:
                x += 1
                order.append(matrix[y][x])
                count += 1
            # 缩小上边界
            minY += 1
            # 避免重复收集元素，及时检查收集数量
            if count == total:
                break

            # 向下收集
            while y < maxY:
                y += 1
                order.append(matrix[y][x])
                count += 1
            # 缩小右边界
            maxX -= 1
            # 检查结果
            if count == total:
                break

            # 向左收集
            while x > minX:
                x -= 1
                order.append(matrix[y][x])
                count += 1
            # 缩小下边界
            maxY -= 1
            # 检查结果
            if count == total:
                break

            # 向上收集
            while y > minY:
                y -= 1
                order.append(matrix[y][x])
                count += 1
            # 缩小左边界
            minX += 1
            # 检查结果
            if count == total:
                break
        
        return order
```

时间复杂度O(n)，其中`n`是输入矩阵所有元素的个数；
空间复杂度O(n)，因为需要order列表来收集所有元素。