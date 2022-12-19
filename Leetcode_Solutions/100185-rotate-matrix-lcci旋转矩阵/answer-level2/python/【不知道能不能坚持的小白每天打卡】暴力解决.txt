### 解题思路
题目提示了要不占用额外内存空间，那就是叫我们疯狂调换两个元素呗。提交完发现N==2的时候错了，那直接给他补一个N==2的情况，其实应该也是可以写进去两个for里面，因为要上班了，就暴力解决完打个卡先。

**本题关键思路**：就默认顺时针旋转90°吧。拿示例1举个例子，就是1跟3换，7跟3换，9跟3换的一个循环，然后4换2，8换2，6换2。拿示例24x4的话就是13换1，12换1，10换1。每一个对应的坐标都是换3次。剩下的就是小心点算坐标就完了。当然需要注意的是，从4开始，就有内圈了（3的内圈就1个数）。我的建议是先把3x3写出来，然后加第一层for，用i把该换的0换掉；然后再加一层for，用j把该换的0换掉。你会发现都是对称的，小心一点就不会写错了。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        if N > 2:
            for j in range(N-2):
                for i in range(j, N-1-j):
                    # 对称的坐标互换，草稿纸写一圈就懂了
                    matrix[j][i], matrix[i][N-1-j] = matrix[i][N-1-j], matrix[j][i]
                    matrix[N-1-i][j], matrix[j][i] = matrix[j][i], matrix[N-1-i][j]
                    matrix[N-1-j][N-1-i], matrix[N-1-i][j] = matrix[N-1-i][j], matrix[N-1-j][N-1-i]
        # 懒，就直接把2写了
        elif N == 2:
            matrix[0][1], matrix[0][0] = matrix[0][0], matrix[0][1]
            matrix[1][0], matrix[0][0] = matrix[0][0], matrix[1][0]
            matrix[1][1], matrix[1][0] = matrix[1][0], matrix[1][1]


```