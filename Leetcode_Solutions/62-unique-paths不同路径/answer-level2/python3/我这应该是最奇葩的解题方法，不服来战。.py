
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a = m + n - 2
        b = min(m, n) - 1
        result = math.factorial(a) // math.factorial(b) // math.factorial(a - b)
        return result