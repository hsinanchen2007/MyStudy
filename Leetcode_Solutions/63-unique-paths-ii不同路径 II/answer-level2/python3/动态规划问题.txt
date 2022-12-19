def uniquePathsWithObstacles(self, obstacleGrid):
    r, c = len(obstacleGrid), len(obstacleGrid[0])
    cur = [0] * c
    cur[0] = 1 - obstacleGrid[0][0]

    for i in range(1, c):
        cur[i] = cur[i-1]*(1 - obstacleGrid[0][i])

    for i in range(1, r):
        cur[0] *= (1 - obstacleGrid[i][0])
        for j in range(1, c):
            cur[j] += (cur[j - 1] + cur[j])*(1 - obstacleGrid[i][j])

    return cur[-1]