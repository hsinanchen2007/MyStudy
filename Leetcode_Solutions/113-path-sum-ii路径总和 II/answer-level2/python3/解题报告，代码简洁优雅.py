如示例所示，问题的解可以分解为：

[
5 + [5的左子树遍历],
5 + [5的右子树遍历]
]
进一步可以分解为:

[
5 + 4 + [4的左子数遍历]
5 + 8 + [8的左子数遍历、右子树遍历]
]

依次类推

```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        # 返回的结果
        res = []
        if root is None:
            return res
        # 当为叶子节点的时候
        if root.left is None and root.right is None:
            if sum == root.val:
                res.append([root.val])
            return res
        # 左子数遍历，找到满足条件的序列
        leftN = self.pathSum(root.left, sum - root.val)
        for n in leftN:
            res.append([root.val] + n)
        # 右子数遍历，找到满足条件的序列
        rightN = self.pathSum(root.right, sum - root.val)
        for n in rightN:
            res.append([root.val] + n)
        return res
        
```
