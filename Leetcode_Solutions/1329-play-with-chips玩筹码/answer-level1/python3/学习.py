class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        even = 0
        odd = 0
        for j in range(len(chips)):
            if(chips[j] % 2 == 0):
                even += 1
            else:
                odd += 1              
        return min(even, odd)