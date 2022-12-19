两种方法都是题目里动态图的模拟，第一种是栈实现的，多维护一个栈，空间复杂度O(2n)=O(n)。第二种是就地修改，空间复杂度O(n)。
第一种
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        stack = [1,1]
        if rowIndex <1:return [1]
        for i in range(rowIndex-1):
            cache = []
            while len(stack)>1:
                cache.append(stack.pop()+stack[-1])
            stack.extend(cache)
            stack.append(1)
            
        return stack
    
# 执行用时 :32 ms, 在所有 Python3 提交中击败了99.55%的用户
# 内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.56%的用户
```
第二种
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        rst = [1]
        for i in range(1,rowIndex+1):
            rst.append(0)
            for j in range(len(rst)-1,0,-1):
                rst[j] = rst[j]+rst[j-1]
        return rst
# 执行用时 :44 ms, 在所有 Python3 提交中击败了84.48%的用户
# 内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.56%的用户
```
