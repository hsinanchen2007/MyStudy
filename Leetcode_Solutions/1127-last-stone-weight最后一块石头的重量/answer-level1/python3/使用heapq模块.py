# 思路：
使用python3的heapq模块，不断取出最大的两个值即可，十分直白的解法。

# 代码：
```
import heapq

class Solution:
    
    def lastStoneWeight(self, stones: List[int]) -> int:
        # heapq模块只实现了最小堆，若要使用最大堆需要把数字转换成相反数
        stones = [-1*s for s in stones]
        heapq.heapify(stones)
        
        while len(stones) > 1:

            y, x = heapq.heappop(stones), heapq.heappop(stones)
            
            if y != x:
                heapq.heappush(stones, y-x)
                
        return -1*stones[-1] if len(stones) == 1 else 0; 
```
# 结果：
执行用时 : 48 ms, 在所有 Python3 提交中击败了 78.27% 的用户
内存消耗 : 13.7 MB, 在所有 Python3 提交中击败了 100.00% 的用户
