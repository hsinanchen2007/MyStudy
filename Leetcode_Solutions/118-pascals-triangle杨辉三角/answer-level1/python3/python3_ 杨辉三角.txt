```python
def generate(numRows):
    # 处理0, 1的特殊情况
    if numRows == 0:
        return []
    if numRows == 1:
        return [[1]]
    # 从第二行开始, 数组两边都是1
    r = [[1]] + [[1, 1] for _ in range(numRows - 1)]
    # 第i行
    for i in range(2, numRows):
        # 第i行的第j个元素, 等于上一行的j, j + 1的元素之和
        for j in range(len(r[i - 1]) - 1):
            r[i].insert(j + 1, r[i - 1][j] + r[i - 1][j + 1])
    return r

print(generate(5))
```