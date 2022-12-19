使用动态规划解法可以达到o(n); 
解题思路：杨辉三角可用在排列组合中，其每行对应着组合数 C{n, m} （n是组合数上标，m为下标）；
1、 C{n, m} = C{m-n, m} 所以只求出前面一半的值，后面就不需要在进行求值
2、n = 0 , n = 1 需要初始化，分别对应值 C{0, m} = 1和 C{1, m} = m
3、 C{n+1, m} = C{n, m} * (m - (n + 1) -1) / (n + 1) 

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex < 0:
            return []
        
        if rowIndex == 0:
            return [1]
        
        result = [0] * (rowIndex + 1)
        for index in range(rowIndex + 1):
            if index == 0:
                result[0] = 1
            elif index == 1:
                result[1] = rowIndex
            elif index <= (rowIndex ) / 2:
                result[index] = result[index - 1] *(rowIndex - index + 1) / index
            else:
                result[index] = result[rowIndex - index]
        
        return result