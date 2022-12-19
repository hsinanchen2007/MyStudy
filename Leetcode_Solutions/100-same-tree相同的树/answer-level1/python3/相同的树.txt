提供一个非递归的思路，用try except来做。

```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        try:
            # 先序遍历
            # 我们假定这是相同的树，所以执行相同的操作
            # 如果不是相同的树，会raiseError
            stack1 = [p]
            stack2 = [q]
            while stack1:
                cur1 = stack1.pop(-1)
                cur2 = stack2.pop(-1)
                # print(cur1.val, cur2.val)
                if cur1.val != cur2.val: # 保证值一样
                    return False
                if cur1.right or cur2.right:
                    stack1.append(cur1.right)
                    stack2.append(cur2.right)
                if cur1.left or cur2.left:
                    stack1.append(cur1.left)
                    stack2.append(cur2.left)                  
        except:
            return False
        # 能保证结构一样，且不是子树
        return not (cur1.left or cur1.right) and not (cur2.left or cur2.right)
```