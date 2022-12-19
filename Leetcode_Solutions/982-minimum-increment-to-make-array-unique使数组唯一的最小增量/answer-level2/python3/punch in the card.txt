### 解题思路

kick the card. 
Again, I will give you source. 

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A)==0:
            return 0
        A.sort()
        now=A[0]-1
        out=0
        #print(A)
        for num in A:
            #print("num",num,"now",now,"out",out)
            if num<=now:
                out+=now+1-num
                now+=1
            else:
                now=num
        return out

```