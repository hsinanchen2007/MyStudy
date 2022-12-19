class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        # B = List[List[]]
        # 翻转每一行
        for line in A:
            for row_index in range(len(line)):
                if row_index < len(line)/2:
                    line[row_index], line[len(line) - row_index - 1] = line[len(line) - row_index - 1] , line[row_index]
                
                line[row_index] = line[row_index] ^ 1
                
    
        return A
                    