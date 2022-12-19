![捕获.PNG](https://pic.leetcode-cn.com/26e0ae06cc5bbb7d4d7cc4c3b32e78d36cf1e2872f1674af90c2369bcac4023e-%E6%8D%95%E8%8E%B7.PNG)
![捕获2.PNG](https://pic.leetcode-cn.com/756f93c1ad240f51b0a1b996031de5aeb3c3db9e9148b62a13d65542416d0a5a-%E6%8D%95%E8%8E%B72.PNG)
```Python []
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return 
        m = len(matrix)
        n = len(matrix[0])
        re = []
        def fun(martix,temp):
            if len(matrix)<=1 or len(matrix[0])<=1:
                if  martix:
                    if len(matrix) == 1 and len(matrix[0]) >=1:
                        for j in range(len(matrix[0])):
                            temp.append(matrix[0][j])
                    elif len(matrix) > 1 and len(matrix[0]) ==1:
                        for j in matrix:
                            temp.append(j[0])
                re.append(temp[:])
                return 
            for i in matrix[0]:
                temp.append(i)
            matrix.remove(matrix[0])
            for j in range(len(matrix)):
                temp.append(matrix[j][-1])
                matrix[j].pop()
            for j in range(len(matrix[0])):
                temp.append(matrix[-1][-j-1])
            matrix.remove(matrix[-1])
            for j in range(len(matrix)):
                temp.append(matrix[-j-1][0])
                matrix[-j-1].remove(matrix[-j-1][0])
            fun(matrix,temp)
        fun(matrix,[])
        return re[0]
```