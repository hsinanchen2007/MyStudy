### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res=[]
        n=len(matrix)
        if n==0:
            return res
        m=len(matrix[0])
        t,r,b,l=0,m-1,n-1,0
        tar=0
        while tar<n*m:
            for i in range(l,r+1):
                # 从左到右
                tar+=1
                res.append(matrix[t][i])
                print('ti:',t,i)
            # 下移一行         
            t+=1

            for j in range(t,b+1):
                # 从上到下
                tar+=1
                res.append(matrix[j][r])
                print('jr:',j,r)
            # 右 移一列
            r-=1

            for k in range(r,l-1,-1):
                # 当上大于下时就应该退出
                if b<t:
                    return res
                # 从右到左
                tar+=1
                res.append(matrix[b][k])
                print('bk:',b,k)
            # 上移一行
            b-=1

            for h in range(b,t-1,-1):
                # 当右小于左时就应该退出
                if r<l:
                    return res
                tar+=1
                res.append(matrix[h][l])
                print('hi:',h,l)
            # 左移一列
            l+=1

        return res
```