直接比较每一行的对角位置是否相等，即前一行的l[:-1]与下一行的l[1:]比较即可。
```
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        for x in range(0,len(matrix) - 1):
            if matrix[x][:-1] != matrix[x + 1][1:]:
                    return False
        return True
```
再来一种一行解决的版本（PS：为什么都喜欢写这种一行的代码呢d=====(￣▽￣*)b）
```
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        return len(list(filter(lambda x : matrix[x][:-1] == matrix[x+1][1:],range(0,len(matrix)-1)))) == len(matrix)-1
```
