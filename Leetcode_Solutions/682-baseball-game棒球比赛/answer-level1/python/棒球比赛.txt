执行用时 : 48 ms, 在Baseball Game的Python3提交中击败了93.24% 的用户 内存消耗 : 12.9 MB, 在Baseball Game的Python3提交中击败了99.26% 的用户
```python
class Solution:
    def calPoints(self, ops: List[str]) -> int:
        j = 0
        while j <= len(ops)-1: 
            if ops[j] == "C":
                ops.pop(j)
                ops.pop(j-1)
                j -= 2
            j += 1
        s = [0 for i in ops]
        for i in range(len(ops)):
            if ops[i] == 'D':
                s[i] = int(s[i-1]) * 2  
            elif ops[i] == '+':
                s[i] = int(s[i-1]) + int(s[i-2])
            else:
                s[i] = int(ops[i])
        return sum(s)
```