### 解题思路
根据N值进行转换赋值

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        import copy
        # 翻转列表：如例子：
        # 1 2 3  |  7 8 9
        # 4 5 6  |  4 5 6
        # 7 8 9  |  1 2 3
        new_list = copy.deepcopy(matrix[::-1])
        rows = len(new_list)

        for j in range(rows):
            # 执行每行
            for index,i in enumerate(new_list):
                # 每行每个值依次遍历赋值翻转后的“列值”
                matrix[j][index] = i[j]
        
        return matrix
        

```