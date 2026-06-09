### 解题思路
最坏时间复杂度O（n*(len1+len2-2）），平均时间复杂度O(n*(len1+len2-2）/2)。空间复杂度O(1)。
此处撰写解题思路
1.先用-1标记原矩阵中为1的点，矩阵长len1，宽len2
2.矩阵中最远距离为：maxdis = len1+len2-2。所以最多遍历maxdis次矩阵
3.第一次遍历更新距离为1的点，第二遍更新距离为2的，逐步更新。
4.注意到每个点最多更新一次，所以用account来记录已更新点数。当account = 所有矩阵中点数说明已经更新完毕。

注：节省空间复杂度，直接在原来的数组上修改。
### 代码

```python3
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        len1 = len(matrix)
        len2 = len(matrix[0])

        maxacc = len1 * len2
        account = 0

        for h in range(0, len1, 1):
            for r in range(0, len2, 1):
                if matrix[h][r] == 1:
                    matrix[h][r] = -1
                else:
                    account += 1                    

        for distense in range(1, len1 + len2 - 1, 1):
            for h in range(0, len1, 1):
                for r in range(0, len2, 1):
                    if matrix[h][r] == -1:
                        if self.Good(matrix, len1, len2, distense, h, r):
                            matrix[h][r] = distense
                            account += 1
                            if account == maxacc:
                                return matrix
        return matrix

    def Good(self, D, len1, len2, distense, h, r):
        if h - 1 >= 0 and D[h - 1][r] == distense - 1:
            return True
        if h + 1 <= len1 - 1 and D[h + 1][r] == distense - 1:
            return True
        if r - 1 >= 0 and D[h][r - 1] == distense - 1:
            return True
        if r + 1 <= len2 - 1 and D[h][r + 1] == distense -1:
            return True
        return False
```