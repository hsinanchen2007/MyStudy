思路：
遍历数组，遇到0在后面插入一个0，然后删除一个数组尾的数。

```
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        i = 0
        n = len(arr)            
        while i < n:
            if arr[i] == 0:
                arr.insert(i,0) 
                arr.pop()      
                i += 2          
            else:
                i += 1
```
