### 解题思路
复写后把列表最后一位pop即可 o(n2)

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        i = 0
        while i < n-1:
            if arr[i] == 0 :
                arr.insert(i,0)
                arr.pop()
                i += 2
            else:
                i += 1
        
            



```