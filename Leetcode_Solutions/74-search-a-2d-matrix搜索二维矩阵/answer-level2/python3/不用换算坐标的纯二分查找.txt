![image.png](https://pic.leetcode-cn.com/7db57860527497df505ea5f8fd0198cc94fe93c3d7906954dac04ef4d58cd052-image.png)

把二维矩阵直接降维，空间大是大，但不见得很慢

```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        a=[]
        for m in matrix:
            a+=m
        i,j=0,len(a)-1
        while i<=j:
                k=(i+j)//2
                if a[k]<target:
                    i=k+1
                elif a[k]>target:
                    j=k-1
                else:
                    return True
        return False
```
