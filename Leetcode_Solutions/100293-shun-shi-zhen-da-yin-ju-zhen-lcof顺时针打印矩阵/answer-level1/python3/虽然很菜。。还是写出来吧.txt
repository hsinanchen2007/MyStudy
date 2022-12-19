### 解题思路
暴力解法，先从第一行开始遍历，到头后遍历最后一列到达最后一行；再从尾往前遍历。。。等到lists没有增加，即证明遍历完成。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []: return []
        temp = i = j = 0
        lx,ly = len(matrix[0]),len(matrix)
        lists = {(0,0):0} #存放坐标，且防止重复遍历；原本是list，但会超时，所以改为字典。
        res = []
        while len(lists)>temp:
            temp = len(lists)
            if ((i,j+1) not in lists) and (j+1<lx) :
                for k in range(j+1,lx):
                    if (i,k) not in lists:
                        lists[(i,k)] = 0
                        j = k
            elif ((i,j-1) not in lists) and (j-1>=0):
                for k in range(j-1,-1,-1):
                    if (i,k) not in lists:
                        lists[(i,k)] = 0
                        j = k
            if ((i+1,j) not in lists) and (i+1<ly) :
                for k in range(i+1,ly):
                    if (k,j) not in lists:
                        lists[(k,j)] = 0
                        i = k
            elif ((i-1,j) not in lists) and (i-1>=0):
                for k in range(i-1,-1,-1):
                    if (k,j) not in lists:
                        lists[(k,j)] = 0
                        i = k
        for i in lists:
            res.append(matrix[i[0]][i[1]])
        return res
```