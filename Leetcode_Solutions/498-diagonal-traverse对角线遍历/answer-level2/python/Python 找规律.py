个人感觉这种题还是偏向于找规律一点，如果刷题为了面试的，可以不用太纠结这种题。

一共找到三条规律，假定矩阵的形状是`(xsize, ysize)`：
1. 对象线规律（1
    对角线上的元素之和是固定的，范围在`range(xsize + ysize - 1)`内，依次递增

2. 对角线规律（2
    遍历的时候，如果对角线之和是奇数，则逆序遍历，否则，顺序遍历

3. 起始坐标终止坐标规律
    以横坐标为例，`x_start = min(diagonal_sum, xsize - 1)`，`x_end = max(diagonal_sum - ysize + 1, 0)`，同理`y`也可以找出类似的规律

```python
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return list()

        xsize, ysize = len(matrix), len(matrix[0])
        diagonal_num, result = xsize + ysize - 1, list()

        for dia_sum in range(diagonal_num):
            tmp = list()  # 暂存当前对角线遍历得到的值

            # 找规律，x坐标的起始和终止位置
            x_start = min(dia_sum, xsize - 1)
            x_end = max(0, dia_sum - ysize + 1)
            
            # 根据起始坐标直接遍历即可
            for x in range(x_start, x_end - 1, -1):
                tmp.append(matrix[x][dia_sum - x])
            
            # 如果当前对角线是要逆序遍历的，那就逆序
            if dia_sum % 2:
                tmp = reversed(tmp)

            # 将对角线遍历的值加到最终结果里面
            result.extend(tmp)

        return result
```