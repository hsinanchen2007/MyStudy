![微信图片_20190915205008.png](https://pic.leetcode-cn.com/92bddeeace1e2f82a132eb00e503525615a0f8fd3088d25d5a83887af1ea8fa9-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190915205008.png)

因为是二叉搜索树，满足左子树值小于节点，有子树值均大于节点，
判断target和节点值大小，如果target大于节点值，那么添加节点右子树，target小于节点值，添加节点左子树，
并将与target最接近的节点值保存在value_min中。

```python []
class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        if not root:
            return
        min_val = float('inf')
        temp = 0
        value_min = 0
        stack = [(root,root.val)]
        while stack:
            node,value = stack.pop(0)
            temp = abs(value-target)
            if min_val>temp:
                min_val = temp
                value_min = value
            if value>target and node.left:
                stack.append((node.left,node.left.val))
            elif value<target and node.right:
                stack.append((node.right,node.right.val))
            elif value == target:
                return value
        return value_min
```

