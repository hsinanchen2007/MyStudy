### 解题思路
此处撰写解题思路
做好全为1的杨辉三角，
从第二行开始
1到n-1都是上一行m-1和m处的和
### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res=[[1 for j in range(i)] for i in range(1,numRows+1)]
        for n in range(2,numRows):
            for m in range(1,n):
                res[n][m]=res[n-1][m-1]+res[n-1][m]
        return res

```