### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        dic=[]
        rows=len(mat)
        
        for i in range (rows):
            dic.append([i,sum(mat[i])])

        dic=sorted(dic,key=lambda x:x[1])

        ans=[]
        for i in range(rows):
             ans.append(dic[i][0])
        return ans[:k]
            
        
        
                        


```