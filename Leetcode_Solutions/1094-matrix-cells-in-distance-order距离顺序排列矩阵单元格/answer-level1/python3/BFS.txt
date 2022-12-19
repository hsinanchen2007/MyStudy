```
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        ans = []
        ans.append([r0,c0])
        stack = [[r0,c0]]
        while 1:
            next_stack = []
            cnt = []
            while stack:
                [r,c] = stack.pop()
                if r < R - 1 and r >= r0 and [r+1,c] not in cnt: #右移动一格
                    cnt.append([r+1,c])
                    next_stack.append([r+1,c])
                if r > 0 and r <= r0 and [r-1,c] not in cnt: #左移一格
                    cnt.append([r-1,c])
                    next_stack.append([r-1,c])
                if c < C - 1 and c >= c0 and [r,c+1] not in cnt:#上移一格
                    cnt.append([r,c+1])
                    next_stack.append([r,c+1])
                if c > 0 and c <= c0 and [r,c-1] not in cnt: #下移一格
                    cnt.append([r,c-1])
                    next_stack.append([r,c-1])
            for [r,c] in cnt:
                ans.append([r,c])
            if not next_stack:
                break
            else:
                stack = next_stack
                next_stack = []
        return ans
```
