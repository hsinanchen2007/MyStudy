### 解题思路
此处撰写解题思路
倒叙查找 在插入时移出最后一位
### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        for i in range(len(arr)-1,-1,-1):
            if arr[i]==0:
                arr.insert(i+1,0)
                arr.pop(-1)
```