**内部移动**
- 用`fang==1`表示斜上移动，`fang==-1`表示斜下移动


**边界移动**
- **边界**：指的是矩阵最外则的边
- 向右移：要出边界的点在上边界和下边界，不包括上边界最右边的点，包括下边界最左边的点
- 向下移：否则就是向下移

**结束移动**
- 根据不同的情况更新位置后还是出边界，则终止循环

```python
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        fang=1
        res=[]
        i=j=0
        while 0<=i<len(matrix) and 0<=j<len(matrix[0]):
            res.append(matrix[i][j])
            i+=-fang;j+=fang #更新内部移动
            if not (0<=i<len(matrix) and 0<=j<len(matrix[0])):
                i-=-fang;j-=fang#出边界的点退回边界
                if (i==0 or i==len(matrix)-1) and j!=len(matrix[0])-1:#更新边界移动
                    j+=1
                else:
                    i+=1
                fang*=-1#改变接下来内部移动的方向
        return res
```

