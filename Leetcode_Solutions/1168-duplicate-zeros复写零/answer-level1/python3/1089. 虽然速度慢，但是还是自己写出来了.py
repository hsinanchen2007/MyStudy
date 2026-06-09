### 解题思路
1. 遇到0，那么依次向后移一位，并将下一位置为0
2. 因为下一位置0，所以移动步数应为2步。
3. 如果没遇到0，那么就移动1步。
4. 循环到len(arr)-1为止，因为有arr[i+1]，注意一下len(arr)-1这个边界条件

### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        
        while i < len(arr)-1:
            if arr[i] == 0:
                j = len(arr) - 2
                while j > i:
                    arr[j+1] = arr[j]
                    j -= 1
                arr[i+1] = 0
                
                i += 2
            else:
                i += 1


```