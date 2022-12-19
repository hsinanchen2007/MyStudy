![image.png](https://pic.leetcode-cn.com/73aa9b079d5f0502f9b6a7debd5b62b44ccf2665f007c1e23d8534bbb031a7fd-image.png)

将原数组周围用-1填充，构成新数组，结果i行j列的值即为该数组i行j列为左上角元素的3X3矩阵的和+加上-1的个数，再除以 9减去 -1的个数
```
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        r=len(M)
        c=len(M[0])
        M.insert(0,[-1]*c)
        M.append([-1]*c)
        for i in range(len(M)):
            M[i].insert(0,-1)
            M[i].append(-1)
 
        res=[]
        for i in range(r):
            row=[]
            for j in range(c):
                lst=[M[i][j],M[i][j+1],M[i][j+2],M[i+1][j],M[i+1][j+1],M[i+1][j+2],M[i+2][j],M[i+2][j+1],M[i+2][j+2]]
                n=lst.count(-1)                
                item=int((sum(lst)+n)/(9-n))
                row.append(item)
            res.append(row)
        return res
```
