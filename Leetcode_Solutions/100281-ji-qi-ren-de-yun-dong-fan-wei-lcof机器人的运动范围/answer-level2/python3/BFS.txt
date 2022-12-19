class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        q = [(0,0)]
        count = 1
        dx = [-1,1,0,0]
        dy = [0,0,1,-1]
        result = [[0]*n for _ in range(m)]  # m行n列
        result[0][0] = 1
        while q:
            cur_i,cur_j = q.pop(0)
            for i in range(4):
                nex_i = cur_i + dx[i]
                nex_j = cur_j + dy[i]
                if self.is_valid(nex_i,nex_j,k,m,n) and not result[nex_i][nex_j]:  # 未访问才能加入到队列中
                    result[nex_i][nex_j] = 1
                    count += 1
                    q.append((nex_i,nex_j))
        return count

    
    def is_valid(self,i,j,k,m,n):
        if i < 0 or j < 0 or i >=m or j>=n:
            return False
        h_i = i // 100
        t_i = i % 100 // 10
        g_i = i % 100 % 10
        h_j = j // 100
        t_j = j % 100 //10
        g_j = j % 100 % 10
        total = h_i + t_i + g_i + h_j + t_j + g_j
        return True if total <= k else False