class Solution():
    def findNumberIn2DArray(self,matrix,target):
        for i in matrix:
            if i and target <= i[-1]:
                for j in range(len(i)):
                    if i[j] == target:
                        return True
        return False