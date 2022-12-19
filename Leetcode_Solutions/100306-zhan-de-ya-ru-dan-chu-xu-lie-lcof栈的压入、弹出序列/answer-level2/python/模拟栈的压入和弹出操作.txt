### 解题思路
直接模拟栈的压入和弹出操作：
建立一个空栈，该压入时就压入，压入后检查是不是需要弹出，如果需要弹出，再检查弹出后是否还需要弹出，直到不能弹出为止，则继续压入
如果压入的完了，但是弹出的还没有完，那么就不是它的一种弹出

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        """直接模拟栈的压入和弹出操作"""
        if len(pushed)!=len(popped):
            return False
        tmp=[]
        i=0
        j=0
        while i<len(pushed):
            tmp.append(pushed[i])
            while tmp and tmp[-1]==popped[j]:
                tmp.pop()
                j+=1
            i+=1
        return len(tmp)==0

```