思路超级简单，类似剥洋葱，一层一层剥开它的心！
加个try--except--else，搞定啦！

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        rst=[]
        while matrix:
            try:            
                a,b,c,d=[],[],[],[] ## 方便后面计算简洁
                a=matrix.pop(0) ## 剥掉上
                b=[matrix[x].pop() for x in range(len(matrix))] ## 剥掉右
                c=matrix.pop()[::-1]  ## 剥掉下
                d=[matrix[x].pop(0) for x in range(len(matrix))][::-1]  ## 剥掉左
            except:
                rst.extend(a+b+c+d)
            else:
                rst.extend(a+b+c+d)
            
        return rst
```
