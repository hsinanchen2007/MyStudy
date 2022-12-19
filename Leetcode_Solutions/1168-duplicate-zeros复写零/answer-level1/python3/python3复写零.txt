### 解题思路
逐个元素进行移动，执行用时长。

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i=0
        while i<len(arr):
            if arr[i]==0:
                j=len(arr)-2
                while j>=i:
                    arr[j+1]=arr[j]
                    j-=1
                i+=2
            else:
                i+=1
```