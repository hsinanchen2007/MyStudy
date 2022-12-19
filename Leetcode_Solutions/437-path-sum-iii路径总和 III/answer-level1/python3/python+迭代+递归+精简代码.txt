### 解题思路
两种方法，利用tmp记录该节点的父节点能构成的所有不同路径的和，组成一个list。
法一：迭代

### 代码

```python3

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:        
        stack = [(root,[])]
        res = 0       
        while stack:
            node, tmp = stack.pop()
            if not node: continue
            tmp = [i+node.val for i in tmp] + [node.val]
            res += tmp.count(sum)
            stack.append((node.left,tmp))
            stack.append((node.right,tmp))  
        return res

```
法二：递归
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def helper(root,tmp):
            if not root: return 0
            tmp = [num + root.val for num in tmp] + [root.val]
            return tmp.count(sum)+helper(root.left, tmp)+helper(root.right, tmp)
        return helper(root, [])
```
