```
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if k== 0: return 1
        result_map = {}

        def is_position_valid(pos:tuple):
            if not(0 <= pos[0] < m and 0<= pos[1] < n): return False
            if sum(sum(int(i) for i in str(p)) for p in pos) > k: return False
            return True
        
        def dfs(pos:tuple):
            if pos not in result_map:
                if is_position_valid(pos):
                    result_map[pos] = 1
                    dfs((pos[0] + 1, pos[1]))
                    dfs((pos[0], pos[1] + 1))
                else:
                    result_map[pos] = 0
        dfs((0,0))
        return len([k for k in result_map if result_map[k]])


```
