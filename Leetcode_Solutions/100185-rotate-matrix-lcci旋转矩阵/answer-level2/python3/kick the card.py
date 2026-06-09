### 解题思路

punch in the card. 
Again, I will give you the code. 

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        import copy
        tmp=copy.deepcopy(matrix)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[j][len(matrix[0])-1-i]=tmp[i][j]
                #print(i,j,tmp[i][j])



```