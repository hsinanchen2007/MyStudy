利用栈对二叉树进行遍历，用一个额外的数组保存所有二叉树路径的节点和，判断每个保存节点和的数组里有多少个和sum相等的数即可。

```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        
        stack = [(root,[root.val])]
        res = 0

        while stack:
            node,temp = stack.pop()
            res += temp.count(sum)
            temp += [0]
            if node.left:
                arr = [i+node.left.val for i in temp]
                stack.append((node.left,arr))
            
            if node.right:
                arr = [i+node.right.val for i in temp]
                stack.append((node.right,arr))
        
        return res
```
