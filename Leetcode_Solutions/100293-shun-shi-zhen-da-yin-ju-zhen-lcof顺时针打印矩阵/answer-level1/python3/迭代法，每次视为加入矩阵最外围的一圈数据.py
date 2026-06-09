![image.png](https://pic.leetcode-cn.com/2a88c5dd8c1a2859c68f18577d57f398cd3b362a3c4047875504f15bc6b162c8-image.png)

每次迭代视为加入矩阵最外围的一圈数据，将中间的一部分数据继续迭代

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []: return []
        
        def fun(mat):
            temp = []
            #如果只剩一行或者一列
            if len(mat) == 1: return mat[0]
            if len(mat[0]) == 1: 
                for k in range(len(mat)):
                    temp.append(mat[k][0])
                return temp
            
            #加上第一行，加完删除
            for i in range(len(mat[0])):
                temp.append(mat[0][i])
            mat.pop(0)
            
            #加上最后一列，加完删除
            for j in range(len(mat)):
                temp.append(mat[j].pop())
            
            #加上最后一行，加完删除
            for i in reversed(range(len(mat[0]))):
                temp.append(mat[len(mat)-1][i])
            mat.pop()
            
            #加上第一列，加完删除
            for j in reversed(range(len(mat))):
                temp.append(mat[j].pop(0))
            
            if len(mat) == 0 or len(mat[0]) == 0: return temp
            else: return temp+fun(mat)
        
        return fun(matrix)

```
