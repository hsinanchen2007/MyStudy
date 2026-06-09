### 解题思路
暴力+剪枝
时空复杂度O(n)
额外添加list，存储前面list的和，遍历和列表，确认存在三个子列表
为什么执行效果这么好？！我有点不明白！
执行用时：80 ms, 在所有 Python3 提交中击败了95.22%的用户
内存消耗：18.4 MB, 在所有 Python3 提交中击败了98.29%的用户

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        B=[A[0]]
        for i in range(1,len(A)):
            B.append(A[i]+B[i-1])
        if B[-1]%3!=0:
            return False
        i=B[-1]/3
        j=0
        for k in range(len(B)-1):
            if B[k]==i*2 and j>0:return True
            if B[k]==i:j+=1      
        return False     
```