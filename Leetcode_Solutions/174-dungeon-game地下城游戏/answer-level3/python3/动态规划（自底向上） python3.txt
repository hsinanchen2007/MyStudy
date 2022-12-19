# 题解
## 动态规划
![在这里插入图片描述](https://pic.leetcode-cn.com/cfd1f231f26bf5e48883040eb8e5a757dd43108bc3e592690c72ba332828d936.png)
$dp[i][j]$表示到达房间$dungeon[i][j]$所需的最小生命值。
若从左上角递推到右下角（自顶向下），当前位置的最小生命值和当前位置尚存的生命值对后续结果会产生很大影响，故放弃这个思路，选择从右下角递推到左上角（自下而上）。

 1. 初始化地下城$dungeon$的行$m$和列$n$
 2. 初始化$dp=[[0,\cdots,0],\cdots,[0,\cdots,0]]$为$m*n$的全零二维数组。
 3. 初始化右下角$dp[m-1][n-1]$，若$dungeon[m-1][n-1]<0$，则到达此房间的最小生命值为$1-dungeon[m-1][n-1]$，否则为$1$，表示只要满足到达此房间的最低生命值$1$即可。
 4. 初始化最后一个行，遍历区间$[n-2,-1)$：
 	+ $dp[-1][i]=max(1,dp[-1][i+1]-dungeon[-1][i])$，若当前位置的$dungeon[-1][i]$小于等于后一位置所需的最小生命值，此时有两种情况：
 		+ $dungeon[-1][i]$为负，表示到达当前位置，自身就需要$|dungeon[-1][i]|+1$滴血，再满足后一位置，所以是$dp[-1][i+1]-dungeon[-1][i]$
 		+ $dungeon[-1][i]$为正，但是小于后一位置的要求，所以当前位置还需要$dp[-1][i+1]-dungeon[-1][i]$滴血。
 	+ 否则，当前位置自带的生命值就可以满足，则到达此位置只需满足最低生命值$1$即可。
 
 5. 同理，对于最后一列做相同的初始化。
 6. 从底向上遍历，遍历行$i$，遍历区间$[m-2,-1)$：
 	+ 遍历列$j$，遍历区间$[n-2,-1)$：
 		+ $dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1)$，正下方和右侧位置所需的最小生命值中的较小者。解释原理和初始化相似。
 
 7. 返回$dp[0][0]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n^{2})$
 - 空间复杂度：$O(n^{2})$

### Python
```python
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m=len(dungeon)
        n=len(dungeon[0])
        dp=[[0]*n for _ in range(m)]
        dp[-1][-1]=max(1,1-dungeon[-1][-1])
        for i in range(n-2,-1,-1):
            dp[-1][i]=max(1,dp[-1][i+1]-dungeon[-1][i])
        for i in range(m-2,-1,-1):
            dp[i][-1]=max(1,dp[i+1][-1]-dungeon[i][-1])
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1)
        return dp[0][0]


```