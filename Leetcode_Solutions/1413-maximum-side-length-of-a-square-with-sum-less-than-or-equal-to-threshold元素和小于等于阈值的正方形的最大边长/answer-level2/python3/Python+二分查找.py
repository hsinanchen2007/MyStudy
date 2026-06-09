### 解题思路
之前比赛的时候在第43个点总是超时，本来以为是自己的搜索算法过于冗杂（while 循环），之后参考别人题解的时候发现大家普遍用的O（n^3）的写法，参考了几种搜索算法后发现JAVA，C++可以过的算法Python总会卡在第43个点上（脚本语言的劣势）
因此只能存在搜索最大算法上想办法优化，采用二分查找的思想，跳出点为n包涵小于阈值的正方形但n+1时不包含。
时间复杂度N^2log(N),

### 代码

```python3
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        n = len(mat)
        m = len(mat[0])
        minum =  min(map(min,mat))
        def overthreshold(summat,t):
            for i in range(n-t+1):
                for j in range(m-t+1):
                    if (summat[i+t][j+t] + summat[i][j] - summat[i][j+t] - summat[i+t][j]) <= threshold:
                        return True
            return False
        
        if minum > threshold:
            return 0
        summat = [[0 for i in range(m+1)] for j in range(n+1)]
        summat[1][1] = mat[0][0]
        for i in range(2,n+1):
            summat[i][1] = summat[i-1][1] + mat[i-1][0]
        for j in range(2,m+1):
            summat[1][j] = summat[1][j-1] + mat[0][j-1]
        for i in range(2,n+1):
            for j in range(2,m+1):
                summat[i][j] = summat[i][j-1] + summat[i-1][j] - summat[i-1][j-1] + mat[i-1][j-1]
        head = 0
        tail = min(m,n)
        if overthreshold(summat,tail):
            return tail
        while head<tail:
            if head + 1==tail and overthreshold(summat,head) and not overthreshold(summat,tail):
                return head
            mid = (head + tail)//2
            if overthreshold(summat,mid):
                head = mid
            else:
                tail = mid
       
```