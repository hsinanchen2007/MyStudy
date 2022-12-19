class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        sum_val = 0
        chen_val = 1
        for i in str(n):
            sum_val+= int(i)
            chen_val*=int(i)

        return chen_val-sum_val