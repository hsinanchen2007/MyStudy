### 解题思路
排序+heap
![image.png](https://pic.leetcode-cn.com/7f8ebfc333019b61111bb6dacaed68817bb2e299305651dc1bd412ab301bb246-image.png)

### 代码

```python3
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        mat=[]
        for i in range(n):
            mat.append([speed[i],efficiency[i]])
        print(mat)
        mat.sort(key=lambda x:x[1],reverse=True)
        print(mat)
        q=[]
        heapq.heapify(q)
        res=total=0

        for i in range(k):
            heapq.heappush(q,mat[i][0])
            total=total+mat[i][0]
            res=max(res,total*mat[i][1])
        for i in range(k,n):
            t=heapq.heappop(q)
            x=max(t,mat[i][0])
            total=total+x-t
            heapq.heappush(q,x)
            res=max(res,mat[i][1]*total)
            #print(q,res,i,mat[i][1],sum(q))
        print(res,res%int(10**9 + 7))
        return res%int(10**9 + 7)

```