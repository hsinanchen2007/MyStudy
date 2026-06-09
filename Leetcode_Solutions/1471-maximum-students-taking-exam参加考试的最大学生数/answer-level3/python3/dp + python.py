```python3
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m, n = len(seats), len(seats[0])
        dp = [[0]*(1 << n) for _ in range(m+1)]

        def validRow(row, s):
            for i in range(n):
                if s & 1 << i and seats[row][i] == '#' or i < n and s & 1 << i and s & 1 << (i+1):
                    return False
            return True
        
        def validTwoRow(s1, s2):
            for i in range(n):
                if s1 & 1 << i and (i > 0 and s2 & 1 << (i-1) or i < n-1 and s2 & 1 << (i+1)):
                    return False
            return True

        for row in range(m)[::-1]:
            for s in range(1 << n):
                # check is s is valid
                if not validRow(row, s):
                    dp[row][s] = -1
                    continue
                for ls in range(1 << n):
                    if dp[row+1][ls] == -1:
                        continue
                    if validTwoRow(s, ls):
                        dp[row][s] = max(dp[row][s], dp[row+1][ls] + bin(s).count('1'))
        return max(dp[0])






```