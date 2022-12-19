### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if sorted(A)!=sorted(B):#字母种类和数目不同返回false
            return False
        
        if A==B:#相同排列，同一字符多于两个即可交换返回TRUE
            if len(set(A))<len(A):
                return True
            else:
                return False
        ind=[]
        for i in range(len(A)):#检测匹配不上的索引，用ind保存
            if A[i]==B[i]:
                pass
            else:
                ind.append(i)
        
        if len(ind)>2:#如果不同的字符对大于两个，返回false
            return False
        else:
            if A[ind[0]]==B[ind[1]] and A[ind[1]]==B[ind[0]]:#交换成功的条件
                return True
                


        
                
        

```