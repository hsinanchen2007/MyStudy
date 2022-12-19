```
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        
        R, C = len(M), len(M[0])
        ans = [[0]*C for _ in M]  # 初始化一个数组 和M相同的行和列
        
        for r in range(R):  #  循环行
            for c in range(C):  # 循环列
                count = 0
                for nr in (r-1, r, r+1):  # 上 当前 下三行
                    for nc in (c-1, c, c+1):  # 左 当前 右三行
                        if 0 <= nr < R and 0 <= nc < C:  # 判断边界条件 比如[0][0]元素相邻的只有3个 左边和上面是没有的
                            ans[r][c] += M[nr][nc]  # 累计求和
                            count += 1  # 算算有多少个元素相加了
                ans[r][c] //= count  # 这也要我解释？
        return ans
```
