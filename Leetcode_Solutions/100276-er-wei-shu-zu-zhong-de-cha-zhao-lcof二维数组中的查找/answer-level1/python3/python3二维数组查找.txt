class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        midPonit = [0, m, m//2]
        #target = 14.5
        if matrix[0][0] > target:
            return False
        if matrix[n-1][m-1] < target:
            return False
        while midPonit[0]+1 != midPonit[1]:
            if matrix[0][midPonit[2]] <= target:
                midPonit[0] = midPonit[2]
            elif matrix[0][midPonit[2]] > target:
                midPonit[1] = midPonit[2]
            midPonit[2] = midPonit[0] + (midPonit[1] - midPonit[0]) // 2
        if matrix[0][midPonit[2]] == target:
            return True
        midPonit = [0, midPonit[0]]
        while midPonit[0] < n and midPonit[1] >= 0:
            if matrix[midPonit[0]][midPonit[1]] < target:
                midPonit[0] += 1
            elif matrix[midPonit[0]][midPonit[1]] > target:
                midPonit[1] -= 1
            elif matrix[midPonit[0]][midPonit[1]] == target:
                return True
        return False