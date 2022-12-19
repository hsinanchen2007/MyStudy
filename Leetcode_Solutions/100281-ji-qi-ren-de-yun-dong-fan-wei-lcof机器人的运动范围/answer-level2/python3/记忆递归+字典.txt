### 解题思路
此处撰写解题思路
我把此类矩阵搜索问题归为一类迷宫问题，都可以利用递归来处理
同时针对此问题，最后需要知道机器人能够走的位置数量，可以利用记忆递归，对于机器人到过的位置存储起来
此时便想到了字典，字典的键为(i,j)元组，值对应可走和不可走对应为1和0，方便最后求和得到可以走的位置总和

**递归的参数为当前位置：i,j,空间范围:m,n,求和边界值:k
当位置超出边界时，返回
当位置坐标在字典中是，返回
当不在字典中时：
1、大于边界，对(i,j)键赋值为0
2、小于边界，对(i,j)键赋值为1，并对四周的方格进行探索，调用递归函数，最后返回。**


### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def sum4ij(i,j):
            sum4=0
            while i!=0:
                sum4+=(i%10)
                i//=10
            while j!=0:
                sum4+=(j%10)
                j//=10
            return sum4
        def movenext(i,j,m,n,k):
            if not(0<=i<m and 0<=j<n):
                return 
            if (i,j) in count:
                return 
            elif sum4ij(i,j)>k:
                count[(i,j)]=0
                return 
            else:
                count[(i,j)]=1
                movenext(i+1,j,m,n,k)
                movenext(i-1,j,m,n,k)
                movenext(i,j+1,m,n,k)
                movenext(i,j-1,m,n,k)
                return
        count,sumcount,i,j={},0,0,0
        movenext(i, j, m, n, k)
        for loc,value in count.items():
            sumcount+=value
        return sumcount



```