得分最高的路径中的最小值一定小于等于A[0][0], A[-1][-1]中的较小值
在[1, min(A[0][0], A[-1][-1])]这个区间中进行二分查找：
如果存在一条路径中的所有值比查找的值大，就将答案暂时设为这个值，并把区间更新到右边的区间进行查找
否则在左边的区间查找．

```
class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        row, col = len(A), len(A[0])
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        def dfs(x, y, limit, visited):
            if x ==row-1 and y==col-1:
                return True 
            visited.add((x, y))
            for direction in directions:
                new_x = x+direction[0]
                new_y = y+direction[1]
                if 0<=new_x<row and 0<=new_y<col and (new_x, new_y) not in visited and A[new_x][new_y]>=limit and dfs(new_x, new_y, limit, visited):
                        return True
            return False

        low = 1
        high = min(A[0][0], A[-1][-1])
        result = 0
        while low<=high:
            mid = low + (high - low)//2
            if dfs(0, 0, mid, visited=set()):
                result = mid
                low = mid+1
            else:
                high = mid-1
        return result
```
