### 解题思路  
逐层访问遍历，当前层的值构成列表加入结果，再构造当前层子节点的列表。
### 代码实现
执行用时 :52 ms, 在所有 Python3 提交中击败了94.25%的用户  
内存消耗 :15 MB, 在所有 Python3 提交中击败了65.94%的用户
1. 迭代
```python
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        root,rst = root and [root],[]
        while root:
            rst.append([x.val for x in root if x])
            root = [y for x in root if x for y in x.children if y]
        return rst
```
2. 递归
```python
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        self.rst = []
        def lo(nodelist):
            if nodelist:
                self.rst.append([x.val for x in nodelist if x])
                lo([y for x in nodelist if x for y in x.children if y])
        lo(root and [root])
        return self.rst
```
执行用时 :52 ms, 在所有 Python3 提交中击败了94.25%的用户  
内存消耗 :15 MB, 在所有 Python3 提交中击败了65.94%的用户