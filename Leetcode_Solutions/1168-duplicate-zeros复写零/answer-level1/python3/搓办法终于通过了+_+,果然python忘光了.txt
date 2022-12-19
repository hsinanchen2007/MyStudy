```
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        if (len(arr) == 0): 
            return 0;
        k = 0
        len1=len(arr)
        for j in range(0,len1):
            if arr[j+k] == 0:
                k+=1
                arr.insert(j+k-1,0)
            if (j+k) >= len1:
                for i in range(k):
                    arr.pop()
                break;
```
