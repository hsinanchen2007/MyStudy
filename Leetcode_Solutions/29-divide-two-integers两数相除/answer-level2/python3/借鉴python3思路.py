#python3
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        tmp  = int(dividend/divisor)
        return min(max(-2**31, tmp), 2**31-1)