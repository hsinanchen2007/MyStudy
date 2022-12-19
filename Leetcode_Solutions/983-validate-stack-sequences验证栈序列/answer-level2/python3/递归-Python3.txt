### 解题思路
每次循环中仅考虑pushed第一个元素在popped中的位置，如果在最后一位在可将pushed[0]与popped[-1]删掉考虑剩下的两列表；
若不在最后一位则考虑以popped.index(pushed[0])为分割点的两列表，因在该点处栈为空栈。

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if len(pushed)==0:
            return True
        if len(pushed)==1:
            if pushed[0]==popped[0]:
                return True
            else:
                return False
        if pushed[0]==popped[-1]:
            return self.validateStackSequences(pushed[1:],popped[:-1])
        else:
            if pushed[0] not in popped:
                return False
            else:
                return bool(\
                int(self.validateStackSequences(\
                pushed[:popped.index(pushed[0])+1],\
                popped[:popped.index(pushed[0])+1]))\
                *\
                int(self.validateStackSequences(\
                pushed[popped.index(pushed[0])+1:],\
                popped[popped.index(pushed[0])+1:]))
                )
```