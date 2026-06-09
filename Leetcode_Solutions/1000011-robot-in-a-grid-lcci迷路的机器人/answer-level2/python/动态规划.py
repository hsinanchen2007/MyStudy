这道题与其他的题区别在于要把地址取到
之前做的提示找到最长路径 或者是否可行
假设dp[i][j] 表示从原点到[i,j]的可行的路径长度
可知如果当前位置是1，则dp[i][j] = 0
因为只能向下或者向右 可知如果这两个位置也是1的话 那么当前位置dp[i][j] = 0 表示这个位置是不可行的
就算这两个位置不是1 也不表示这个位置是可行的 所以需要用dp[i-1][j] dp[i][j-1]来判断 

class Solution(object):
    def pathWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: List[List[int]]
        """
        lenA = len(obstacleGrid)
        if lenA == 0:
            return []
        
        lenB = len(obstacleGrid[0])
        if lenB == 0:
            return []
        
        if obstacleGrid[0][0] == 1 or obstacleGrid[-1][-1] == 1:
            return []

        res = []
        dp = [[0 for _ in range(lenB)] for __ in range(lenA)]
        dp[0][0] = 1
        for i in range(1, lenA):
            if obstacleGrid[i][0] == 1:
                dp[i][0] = 0
            elif dp[i-1][0] == 0:
                dp[i][0] = 0
            else:
                dp[i][0] = dp[i-1][0]+1
        for j in range(1,lenB):
            if obstacleGrid[0][j] == 1:
                dp[0][j] = 0
            elif dp[0][j-1] == 0:
                dp[0][j] = 0
            else:
                dp[0][j] = dp[0][j-1]+1
        for i in range(1, lenA):
            for j in range(1, lenB):
                if  obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                    continue
                if dp[i-1][j] == 0 and dp[i][j-1] == 0:
                    dp[i][j] = 0
                    continue
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1       
        res.append([lenA-1, lenB-1])
        maxvalue = dp[-1][-1]
        if maxvalue == 0:
            return []
        for i in range(lenA-1, -1, -1):
            for j in range(lenB-1, -1, -1):
                if dp[i][j] == maxvalue - 1:
                    res.insert(0, [i, j])
                    maxvalue = maxvalue - 1
        return res



