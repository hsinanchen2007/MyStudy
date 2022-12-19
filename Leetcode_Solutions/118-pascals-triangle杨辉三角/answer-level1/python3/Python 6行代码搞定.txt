class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        res = [[1]]
        for i in range(numRows - 1):
            res.append([sum(j) for j in zip([0]+res[i],res[i]+[0])])
        return res