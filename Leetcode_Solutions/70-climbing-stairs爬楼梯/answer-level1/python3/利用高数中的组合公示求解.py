class Solution:
    def climbStairs(self, n: int) -> int:
        max_2 = n//2
        whole_count = 0
        for i in range(max_2+1):
            points = i+(n-2*i)
            count = 1
            div = 1
            for j in range(i):
                count *= (points-j)
                div *= j+1
            count = count/div
            whole_count += int(count)
        return whole_count