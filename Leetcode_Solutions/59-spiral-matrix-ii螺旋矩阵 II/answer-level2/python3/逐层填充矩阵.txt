逐层填充矩阵
```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        # 空矩阵
        array_list = [[-1 for _ in range(n)] for _ in range(n)]
        # 层数
        lay_num = (n + 1) // 2
        # 按层遍历，从最外层到最内层
        for i in range(lay_num):
            # 当前回字层边长
            this_w = n - 2 * i
            # 内层回字边长
            inner_w = n - 2 * (i + 1)
            if inner_w > 0:
                # 有内层
                lay_size = this_w ** 2 - inner_w ** 2
            else:
                # 无内层，已是最内层
                lay_size = this_w ** 2
            # 当前层遍历所有数字，从左上角开始
            for j in range(lay_size):
                if 0 <= j <= this_w - 1:
                    # 为回字上边
                    r = i
                    c = i + j
                elif this_w - 1 < j <= 2 * (this_w - 1):
                    # 为回字右边
                    r = i + j - (this_w - 1)
                    c = i + this_w - 1
                elif 2 * (this_w - 1) < j <= 3 * (this_w - 1):
                    # 为回字下边
                    r = i + this_w - 1
                    c = i + this_w - 1 - (j - 2 * (this_w - 1))
                elif 3 * (this_w - 1) < j < 4 * (this_w - 1):
                    # 为回字左边
                    r = i + this_w - 1 - (j - 3 * (this_w - 1))
                    c = i
                else:
                    print(i, j)
                    raise ValueError('unknown error')

                # 当前位置数值 （当前层数位置数值 + 当前层数起始基数[外环囊括的所有数字 - 内环囊括的所有数字]）
                array_list[r][c] = j + 1 + (n ** 2 - (n - 2 * i) ** 2)
        return array_list
```
