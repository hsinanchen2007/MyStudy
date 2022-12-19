```
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        self.asr=[]
        if matrix==[]:
            return []
        self.find_outer(matrix)
        return self.asr
    
    def find_outer(self,matrix):
        if len(matrix)==0:
            pass
        elif len(matrix)==1:
            self.asr.extend(matrix.pop(0))
        
        elif len(matrix[1])==1:
            for each in matrix:
                self.asr.extend(each)
        else:
            flag=False
            for each in matrix:
                if each!=[]:
                    flag=True
                    break
            if flag:
                self.asr.extend(matrix.pop(0))
                for each in matrix:
                    self.asr.append(each.pop(-1))
                flag=matrix.pop(-1)
                flag.reverse()
                self.asr.extend(flag)
                l=len(matrix)
                for i in range(l-1,-1,-1):
                    self.asr.append(matrix[i].pop(0))
                self.find_outer(matrix)
```
