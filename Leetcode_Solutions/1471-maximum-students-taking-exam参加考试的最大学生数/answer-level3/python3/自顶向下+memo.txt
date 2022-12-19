    
思路是自顶向下+ 记忆化memo。
dfs 表示的是pre 的状态下， 从第i行开始到结束的最大seats 数目。
check 表示的是 在当前candi 状态下， pre 是之前的状态， 当前第i 行是否符合题意、
    
def maxStudents(self, seats: List[List[str]]) -> int:
        n = len(seats)
        m = len(seats[0])
        # 当前candi 状态， pre 状态，当前i行
        def check(candi, pre, i):
            #candi -> state
            #i -> `
            #pre -> i-1
            for idx in range(m):
                # and前面是定位，后面判断是否能坐
                if (candi & (1 << idx)) and seats[i][idx] == '#':
                    return False
                
                if candi & (1 << idx):
                    # 左面的情况，和左上的情况
                    if idx > 0 and ((candi & (1 << (idx - 1))) or (pre & (1 << (idx - 1)))):
                        return False
                    if idx < m - 1 and ((candi & (1 << (idx + 1))) or \
                                        (pre & (1 << (idx + 1)))):
                        return False
            return True
        #dp[row][state]=max(dp[row−1][last]+state.count())
        import functools
        @functools.lru_cache(None)
        # pre 状态， 从i行开始的 最大seats数目
        def dfs(pre, i):
            #if i == n:
            #    return 0
            if i == len(seats)-1:
                maxCount = -1
                for state in range(2 ** m):
                    if check(state,pre,i):
                        maxCount = max(maxCount, bin(state).count('1'))
                return maxCount
            res = 0
            for candi in range(2 ** m):
                if check(candi, pre, i):
                    res = max(dfs(candi, i + 1) + bin(candi).count('1'), res)
            return res
        
        return dfs(0, 0)