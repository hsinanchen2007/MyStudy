```python
# 时间复杂度还挺好，超过90%+
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0

        # sums为node的父节点已能构成的和，返回最长可延伸到node结束的所有路径所能构成的和列表
        def dfs(node, sums):
            left = right = 0  # 左右的值默认为0
            # 之前的和加当前结点值能构成的新和，以及从当前结点开始算的新和
            temp = [num + node.val for num in sums] + [node.val]
            if node.left:
                left = dfs(node.left, temp)  # 递归
            if node.right:
                right = dfs(node.right, temp)  # 递归
            return temp.count(sum) + left + right

        return dfs(root, [])
```
