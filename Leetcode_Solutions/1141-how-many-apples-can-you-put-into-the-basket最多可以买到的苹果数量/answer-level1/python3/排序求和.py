class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        sum = 0
        num = 0
        for i in sorted(arr):
            sum += i
            if sum <= 5000:
                num += 1
        return num