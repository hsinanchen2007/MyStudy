### 解题思路
循环遍历一遍List，每次给字典添加 键-值：num-0 同时检查当前字典内是否有num的二倍数或者可被2整除的数

### 代码

```python3
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        mp = {}
        
        for num in arr:
            if num / 2 in mp or num * 2 in mp:
                return True
            mp[num] = 0
                
        return False
```