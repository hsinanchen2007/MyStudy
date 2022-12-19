![image.png](https://pic.leetcode-cn.com/a127646a6f6c3c5d9ebf055cf86f33623a27af84e2f34a5656ae65737e155a92-image.png)

```
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) <=2: True
        F1 =  0
        F2 = 0
        counter_2 = 0 
        for i in range(0,len(A)-1):
            if A[i] - A[i+1] ==0:
                pass
            elif A[i] - A[i+1] >0:
               F1 +=1
            else:
                F2 +=1
            if F1 * F2 > 0:
                return False
        return True
```



