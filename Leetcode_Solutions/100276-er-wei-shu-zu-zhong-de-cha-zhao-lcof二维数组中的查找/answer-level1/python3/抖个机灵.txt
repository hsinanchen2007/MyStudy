class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        import numpy as np
        array1 = np.array(matrix)
        if target in array1:
            return True
        else:
            return False