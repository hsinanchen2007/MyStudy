class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        for i in grid:
            for index,j in enumerate(i):
                index_after = len(i)-index-1
                if i[index_after]<0:
                    count += 1
                else:
                    break
        return count
