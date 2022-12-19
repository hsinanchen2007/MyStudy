方法一：
参考了[比赛讨论区的方法](https://leetcode-cn.com/circle/discuss/1I3IVg/view/WSfk3R/) [@haozheyan97](/u/haozheyan97/)
> Problem 4
>这个是典型的轮廓线动态规划题目。每次放置考虑从上到下，从左至右放置。按照这种规律放的话，每次放置，只需要记录从上一行的该格子到该格子前一个的状态。使用状态压缩转为 2 进制即可很方便使用 dp 进行转移。

>But... 如果说记录全盘的状态，则状态数会高达 O(2mn)O(2^{mn})O(2mn)，在这道题的范围下，状态数堪比棋盘上的麦粒那么多。显然，需要一定技巧来减少需要记录的状态量。

>作者：haozheyan97
>链接：https://leetcode-cn.com/circle/discuss/1I3IVg/view/WSfk3R/
>来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


![f](https://pic.leetcode-cn.com/7aa34eef31588fc9e97c98d865b95c9c40e3b9bc3fdcf7a1c4dddd8237610fe9-dp_graph.jpg)
用了一个大小为m+1的滑动窗口，为了方便边界讨论，在上方和左方添加了一行和一列障碍物，注意-1表示了非法状态，所以递推的时候直接跳过

```python
class Solution:
    def domino(self, n: int, m: int, broken: List[List[int]]) -> int:
        brk = set()
        for b in broken:
            brk.add((b[0],b[1]))
        dp = [-1]*(1<<(m+1))
        block = (1<<(m+1))-1
        dp[(1<<(m+1))-1] = 0
        for i in range(n):
            next_dp = [-1]*(1<<(m+1))
            for state in range(1<<(m+1)):
                if block & state != block or dp[state] == -1:
                    continue
                next_dp[(state>>1)|(1<<m)] = max(next_dp[(state>>1)|(1<<m)], dp[state])
            block = (block>>1) | (1<<m)
            dp = next_dp

            for j in range(m):
                next_dp = [-1]*(1<<(m+1))
                next_block = block>>1
                for state in range(1<<(m+1)):
                    if block & state != block or dp[state] == -1:
                        continue
                    if (i,j) in brk:
                        next_dp[(state>>1)|(1<<m)] = max(next_dp[(state>>1)|(1<<m)], dp[state])
                        next_block = next_block | (1<<m)
                    else:
                        next_dp[state>>1] = max(next_dp[state>>1], dp[state])
                        if state & 1 == 0:
                            next_dp[(state>>1)|(1<<m)] = max(next_dp[(state>>1)|(1<<m)], dp[state]+1)
                        if state & (1<<m) == 0:
                            next_dp[(state>>1)|(1<<m)|(1<<(m-1))] = max(next_dp[(state>>1)|(1<<m)|(1<<(m-1))], dp[state]+1)
                dp = next_dp
                block = next_block
        return max(dp)
```

方法二：
二分圖最大匹配，匈牙利算法（注意其實可以跳過染色的部分，無論是從哪種顏色開始dfs都是可以的）
```python
from collections import defaultdict

class Solution:
    def domino(self, n: int, m: int, broken: List[List[int]]) -> int:
    	def dfs(cur, visited, match):
    		for nxt in edges[cur]:
    			if nxt not in visited:
    				visited.add(nxt)
    				if match.get(nxt,-1) == -1 or dfs(match[nxt],visited,match):
    					match[cur] = nxt
    					match[nxt] = cur
    					return True
    		return False

    	def hungarian():
    		ans = 0
    		match = {}
    		for i in range(n):
    			for j in range(m):
    				cur = i*m + j
    				if (i,j) not in brk and match.get(cur,-1) == -1:
    				# if (i,j) not in brk and (i+j) & 1 and match.get(cur,-1) == -1:
    					visited = set()
    					# visited.add(cur)
    					if dfs(cur, visited, match):
    						ans += 1
    		return ans

    	edges = defaultdict(list)
    	brk = set()
    	for b in broken:
    		brk.add((b[0],b[1]))
    	for i in range(n):
    		for j in range(m):
    			if (i,j) in brk:
    				continue
    			cur = i*m + j
    			if j+1 < m and (i,j+1) not in brk:
    				nxt = cur + 1
    				edges[cur].append(nxt)
    				edges[nxt].append(cur)
    			if i+1 < n and (i+1,j) not in brk:
    				nxt = cur + m
    				edges[cur].append(nxt)
    				edges[nxt].append(cur)
    	# print(edges)
    	return hungarian()
```