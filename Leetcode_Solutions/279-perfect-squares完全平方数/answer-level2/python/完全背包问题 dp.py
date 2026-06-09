### 解题思路
发现从后往前向要更容易理解一些, 首先在纸上画出递归的数结构, subset(i, n)用来表示当前决定选不选第i个, n表示剩余的平方数
但是到最后还是超时了

### 代码

```
class Solution:
    def numSquares(self, n: int) -> int:
        nums = [x**2 for x in range(1, int(n**(0.5))+1)] # 从1开始注意!
        print(nums, n)
        l = len(nums)
        memo = {}
        def solve(i, n):
            key = '%d %d'%(i,n) # 一定要加空格!
            print(i, n)
            if key in memo:
                return memo[key]
            if n==0:
                return 0
            elif i==0:
                # return 1 if nums[i]==n else solve(i, n-1)+1 # 这个else就是只能用1填的情况  
                return n # 没必要递归了
            elif nums[i]>n:
                memo[key] = solve(i-1, n) # 当前数大于背包剩余容量时, 智能不选
            else:
                C = solve(i, n-nums[i])+1 # 情况C就是完全背包问题多出的情况, 重复选nums[i]
                B = solve(i-1, n-nums[i])+1 # 只选一次nums[i]
                A = solve(i-1, n) # 不选nums[i]
                memo[key] = min(A, B, C)
            return memo[key]
        return solve(l-1, n)

```
然后看了题解只能正向的做. 其实就是0-1背包的套路, 本来去掉二维数组变一维后要从后往前遍历, 使计算i时只从i-1的状态转移过来
(dp[i][j]代表前i个数中背包重量装到j时的最小个数)
但因为是完全背包可以重复选, 所以正向遍历, 使得计算i时也可以从i的状态转移过来, beat 5


```python3
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0]*(n+1) # dp[j]代表背包重量为j时所需最少个数
        for i in range(1, n+1):
            dp[i] = i # 因为是求最小, 所以初始化的时候要注意最开始每个状态要初始化为最大, 即它本身 eg:3=1+1+1
            for j in range(1, int(i**(0.5))+1):
                dp[i] = min(dp[i], dp[i-j*j]+1)
        return dp[-1]
```

方法有很多啊, 也可以bfs, 因为是bfs, 所以当n第一次减为0时一定是最短路径, beat 50
```
class node:
    def __init__(self,value,step=0):
        self.value = value
        self.step = step
    def __str__(self):
        return '<value:{}, step:{}>'.format(self.value,self.step)


class Solution:
    def numSquares(self, n: int) -> int:
        queue = [node(n)] # 其实也不用建一个类, 直接用一个元组存就行
        visited = set([node(n).value]) # 这个visited很关键! 因为对每个rest value都要用所有数字去减一遍, 所以之前已经遍历过这个value的话就不用再从这个结点分叉往下走了 相当于剪枝了.
        
        while queue:
            vertex = queue.pop(0)
            residuals = [vertex.value - n*n for n in range(1,int(vertex.value**.5)+1)]
            for i in residuals:
                new_vertex = node(i, vertex.step+1)
                if i==0:                   
                    return new_vertex.step
                    
                elif i not in visited:
                    queue.append(new_vertex)
                    visited.add(i)
                                        
        return -1
```
作者：zi-lai-huo
链接：https://leetcode-cn.com/problems/perfect-squares/solution/python3zui-ji-chu-de-bfstao-lu-dai-ma-gua-he-ru-me/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


而同样是递归,这个只需要80ms beat93
这个类似于分段递归,如果当前段中有满足条件的结果, 就直接返回
```
from math import sqrt
class Solution:
    d = {} # memo
    def numSquares(self, n: int) -> int:
        if n <= 3:
            return n
        if n in self.d:
            return self.d[n]
        a = 2
        b = n
        i = int(sqrt(n))
        while True: 
            # 比如第一次遍历, 在 ((n//2)**0.5, n**0.5]区间内, 最少的完全平方数满足<=2
            # 第二次遍历, 在 ((n//3)**0.5, (n//2)**0.5]区间内, 最少的完全平方数满足<=3
            j = int(sqrt(n // a))
            while i > j:
                b = min(b, 1 + self.numSquares(n - i ** 2))
                if b <= a:
                    self.d[n] = b
                    return b
                i -= 1
            a += 1
```