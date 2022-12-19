# 题解
## 动态规划
$dp[i]$表示$i$最少可以由几个平方数构成。

 1. 初试化$dp=[0,1,2,\cdots,n]$，长度为$n+1$，最多次数就是全由1构成。
 2. 遍历$dp$，对于$i$，遍历区间$[2,n+1)$：
 	+ 遍历所有平方数小于$i$的数$j$，遍历区间$[1,int(\sqrt{i})+1)$：
 		+ $dp[i]=min(dp[i],dp[i-j*j]+1)$。始终保存所有可能情况中的最小值。 
 
 3. 返回$dp[n]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n\sqrt{n})$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def numSquares(self, n: int) -> int:
        dp=[i for i in range(n+1)]
        for i in range(2,n+1):
            for j in range(1,int(i**(0.5))+1):
                dp[i]=min(dp[i],dp[i-j*j]+1)
        return dp[-1]
```


## 广度优先遍历
![在这里插入图片描述](https://pic.leetcode-cn.com/d97573239c82014d675e25e406748a1301a3de655c3e5a5e0566dabeb5e33b0d.png)
因为是广度优先遍历，顺序遍历每一行，所以当节点差出现0时，此时一定是最短的路径。
如绿色所示，若此时节点为0，表示根节点可以由路径上的平方数$\{1,1,9\}$构成，返回此时的路径长度3，后续不在执行。
如红色所示，若节点值在之前已经出现，则不需要再计算，一定不会是最短路径，最短路径还未出现。

借助队列实现广度优先遍历（层次遍历）

 1. 初始化队列$queue=[n]$，访问元组$visited=\{\}$，初试化路径长度$step=0$
 2. 特判，若$n==0$，返回$0$。
 3. 循环条件，队列不为空：
 	 + $step+=1$，因为循环一次，意味着一层中的节点已经遍历完，所以路径长度需要加一。
 	 + 定义当前层中的节点数$l=len(queue)$，遍历当前层的所有节点：
 	 	+ 令$tmp$为队首元素。
 	 	+ 遍历所有可能数$i$的平方数，遍历区间$[1,int(\sqrt{tmp})+1)$：
 	 		+ 定义$x=tmp-i^{2}$
 	 		+ 若$x==0$，返回当前的路径长度。
 	 		+ 若$x\ not\ in\ visited$，表示当前节点未出现过：将该节点入队并在访问数组中加入。
 
 4. 返回$step$

	  

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n*\sqrt{n})$，并不准确
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def numSquares(self, n: int) -> int:
        from collections import deque
        if n == 0: return 0
        queue = deque([n])
        step = 0
        visited = set()
        while(queue):
            step+=1
            l=len(queue)
            for _ in range(l):
                tmp=queue.pop()
                for i in range(1,int(tmp**0.5)+1):
                    x=tmp-i**2
                    if(x==0):
                        return step
                    if(x not in visited):
                        queue.appendleft(x)
                        visited.add(x)
        return step
```
