用递归来解答本题非常简便直观：

基线条件：如果某个节点本身就是叶子节点，那么就直接把它的值转化为字符串，添加到路径列表里，并返回路径列表；如果遇到了None，返回空列表。

调用递归：如果某个节点不是叶子节点，它的左子节点到叶子节点的全部路径为m条，它的右子节点到叶子节点的全部路径为n条，那么该节点到叶子节点的全部路径就是m+n条，我们只要以该节点为起点，对左右子节点分别调用递归函数就能得出结果。


```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        # 基线条件
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [str(root.val)]
        
        # 调用递归函数，遍历左右子节点到叶子节点的全部路径
        # 拼接出该节点到叶子节点的全部路径
        ret = []
        for path in self.binaryTreePaths(root.left):
            ret.append(str(root.val)+'->'+path)
        for path in self.binaryTreePaths(root.right):
            ret.append(str(root.val)+'->'+path)
        return ret
```

