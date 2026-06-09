### 解题思路
内存占用13.6M，速度不太行，代码有点啰嗦，有待提高。
递归方式，向下、向右查找。建立了一个List标记走过的地方，防止重新计算

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def is_access(m,n,k):
            m_sum=m//10+m%10
            n_sum=n//10+n%10
            if m_sum+n_sum>k:
                return False
            else:
                return True
        def recursion(x,y,m,n,count,lt):
            if x>m or y>n:
                return count
            if is_access(x,y,k) and lt[x][y]==0:
                count+=1
                lt[x][y]=1
            if is_access(x,y+1,k) and x<m and y+1<n and lt[x][y+1]==0:
                count=recursion(x,y+1,m,n,count,lt)
            if is_access(x+1,y,k) and x+1<m and y<n and lt[x+1][y]==0:
                count=recursion(x+1,y,m,n,count,lt)
            return count
        x=0
        y=0
        count=0
        lt=[]
        for i in range(m):
            lt.append([])
            for j in range(n):
                lt[i].append(0)
        return recursion(x,y,m,n,count,lt)


```