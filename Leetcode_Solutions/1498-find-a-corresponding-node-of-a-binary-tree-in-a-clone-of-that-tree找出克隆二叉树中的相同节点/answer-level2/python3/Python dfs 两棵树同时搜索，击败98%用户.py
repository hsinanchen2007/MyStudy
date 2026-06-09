![image.png](https://pic.leetcode-cn.com/8ac1252440779b228edcb2b358d6c2e9d73ac46ecf80307bf702f47e73fad11f-image.png)


```
'''
dfs 找相同位置节点即可
'''

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:

        if original is None:
            return None

        if target is original:
            return cloned

        lret = self.getTargetCopy(original.left, cloned.left, target)
        if lret:
            return lret

        rret = self.getTargetCopy(original.right, cloned.right, target)
        if rret:
            return rret

        return None

```
