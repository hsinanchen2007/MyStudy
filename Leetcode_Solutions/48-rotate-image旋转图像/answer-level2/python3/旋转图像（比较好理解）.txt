我的想法是先将二维数组按行逆序，即最后一行变为第一行，倒数第二行变为第二行。。。。。
然后再转置该二维数组。代码如下：
```
 def rotate(matrix: List[List[int]]) -> None:
    matrix.reverse()
    for i in range(len(matrix)):
        for j in range(0, i):
            if i == j:
                continue
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

```
