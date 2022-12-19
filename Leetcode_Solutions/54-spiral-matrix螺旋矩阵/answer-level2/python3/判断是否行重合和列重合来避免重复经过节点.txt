总共遍历的时候要通过四条路径
+ left->right 
+ up->button
+ right->left
+ button->up 
其中第一和第三条路径可能行重合，第二和第四掉路径可能列重合。
分别判断起始行和起始列是否重合即可。
```
import math
class Solution:
    def spiralOrder(self, matrix):
        loop=math.ceil(min(len(matrix),len(matrix[0]))/2)#计算循环的次数
        m=len(matrix)
        n=len(matrix[0])
        result=[]
        for i in range(loop):
            for j in range(i,n-i): #left->right
                result.append(matrix[i][j])

            for k in range(i+1,m-i): # up->button
                result.append(matrix[k][n-i-1])
            
            for j in reversed(range(i,n-i-1)):#right->left
                if m-i-1 == i: #判断是否行重合
                    break
                result.append(matrix[m-i-1][j])
            
            for k in reversed(range(i+1,m-i-1)): #button->up
                if i==n-i-1: #判断是否列重合
                    break
                result.append(matrix[k][i])
            
            loop +=1
        
        return result
```