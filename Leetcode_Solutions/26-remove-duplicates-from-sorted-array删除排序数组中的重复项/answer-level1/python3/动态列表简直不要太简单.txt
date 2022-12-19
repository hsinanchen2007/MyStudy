### 解题思路
直接用一个新的列表去搞就行了多简单

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        copys: [] = []
        previous: int
        is_init: bool = False
        for i in nums:
            if is_init:
                pass
            else:
                previous = i
                is_init = True
                copys.append(i)
                continue

            if i > previous:
                copys.append(i)
                previous = i
        nums.clear()
        for i in copys:
            nums.append(i)
        return len(copys)
```