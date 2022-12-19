### 解题思路
以两个指针start、end进行迭代，每次选出最外面的一圈数字，分四种情况进行旋转（额外用一个一维数组保存第一边数据，以便最后一边的数据可以更新）。完成后，start+1，end-1,进行次圈数据的旋转。直到start>end,结束迭代，所有数据旋转完毕。

### 代码

```python
class Solution(object):
    def rotate(self, matrix):
        start=0
        end=len(matrix)-1
        nums=0

        while start<end:
            cur=[]
            for j in range(start,end+1):
                cur.append(matrix[start][j])
                matrix[start][j]=matrix[end-j+start][start]

            for i in range(start,end+1): 
                matrix[i][start]=matrix[end][i]

            for j in range(start,end+1):
                matrix[end][j]=matrix[end-j+start][end]

            for i in range(end,start-1,-1):
                matrix[i][end]=cur[-1]
                cur.pop()
            start+=1
            end-=1
        return matrix
```