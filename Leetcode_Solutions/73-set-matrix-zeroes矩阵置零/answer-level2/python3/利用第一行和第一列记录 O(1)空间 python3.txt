# 题解
很自然想到借助额外空间保存0的位置，然后对原矩阵进行置0
## 额外空间
 1. 定义两个元组$res\_i,res\_j$，保存矩阵中$0$的行和列索引。
 2. 初始化矩阵行数$m$和列数$n$。
 3. 遍历矩阵，若$matrix[i][j]==0$，将对应的行和列索引加入$res\_i,res\_j$。
 4. 再遍历一次矩阵，若当前位置的行或列索引在行元组或列元组中出现，即$i\ in\ res\_i\ or\ j\ in\ res\_j$，将此位置置为$0$。

### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(M+N)$

### Python

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        res_i=set()
        res_j=set()
        m=len(matrix)
        n=len(matrix[0])
        for i in range(m):
            for j in range(n):
                if(matrix[i][j]==0):
                    res_i.add(i)
                    res_j.add(j)
        for i in range(m):
            for j in range(n):
                if(i in res_i or j in res_j):
                    matrix[i][j]=0
```
### Java（待完成）
## $O(1)$空间
我们利用矩阵的第一行和第一列保存该行或者列是否应被置为0
### 算法流程
 1. 定义$flag\_line=False$，判断第一行是否需要置$0$。定义$flag\_row=False$，判断第一列是否需要置$0$。
 2. 遍历第一列，若第一列中存在$0$，将$flag\_row=True$，表示需要将第一列置$0$。
 3. 遍历第一行，若第一行中存在$0$，将$flag\_line=True$，表示需要将第一行置$0$。
 4. 遍历矩阵，遍历区间，行区间$[1,m)$，列区间$[1,m)$，若$matrix[i][j]==0$，则将对应的行和列记录下来，即将第一行和第一列中对应的位置置为$0$。$matrix[i][0]=matrix[0][j]=0$
 5. 再遍历一次矩阵，若当前位置的行或列索引对应的第一行或者第一列处为$0$，即$matrix[i][0]==0\ or\ matrix[0][j]==0$，将此位置置为$0$。
 6. 根据$flag\_line$，判断是否需要将第一行置为$0$。
 7. 根据$flag\_row$，判断第一列是否需要置$0$。

### 复杂度分析
 - 时间复杂度：$O(M*N)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        flag_line=False
        flag_row=False
        m=len(matrix)
        n=len(matrix[0])
        for i in range(m):
            if(matrix[i][0]==0):
                flag_row=True
                break
        for i in range(n):
            if(matrix[0][i]==0):
                flag_line=True
                break
        for i in range(1,m):
            for j in range(1,n):
                if(matrix[i][j]==0):
                    matrix[i][0]=matrix[0][j]=0
        for i in range(1,m):
            for j in range(1,n):
                if(matrix[i][0]==0 or matrix[0][j]==0):
                    matrix[i][j]=0                    
        if(flag_row):
            for i in range(m):
                matrix[i][0]=0
        if(flag_line):
            for i in range(n):
                matrix[0][i]=0
```