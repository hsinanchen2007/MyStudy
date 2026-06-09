我们让程序来模拟我们输出数字

首先用 begin_i和end_i ,begin_j和end_j 记录下横轴和纵轴的开始和结束位置

然后写出 从左到右 从上到下 从右到左 从下到上 为一个大循环

每当输出了一个横轴就begin_i+1 输出纵轴就end_i-1

以此类推 注意边值问题

记录输出了多少个数字 如果输出了所有数字就跳出循环
 

``` python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        begin_i=0
        begin_j=0
        end_i=len(matrix)
        if end_i==0:
            return []
        end_j=len(matrix[0])
        if end_j==0:
            return []
        numbs=0
        result=[]
        sum_numbs=end_i*end_j
        while numbs!=sum_numbs:
            for x in range(begin_j,end_j):
                result.append(matrix[begin_i][x])
                numbs+=1
            begin_i+=1
            if numbs==sum_numbs:
                break
            for z in range(begin_i,end_i):
                result.append(matrix[z][x])
                numbs+=1
            end_j-=1
            if numbs==sum_numbs:
                break
            for x in range(end_j-1,begin_j-1,-1):
                result.append(matrix[z][x])
                numbs+=1
            end_i-=1
            if numbs==sum_numbs:
                break
            for z in range(end_i-1,begin_i-1,-1):
                result.append(matrix[z][x])
                numbs+=1
            begin_j+=1
            if numbs==sum_numbs:
                
                break
        return result
```