class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        int2str = str(n)
        sum = 0
        dot = 1
        for i in range(len(int2str)):
            sum += int(int2str[i]) 
            dot *= int(int2str[i])
            print(sum,dot)
        final = dot - sum
        return final