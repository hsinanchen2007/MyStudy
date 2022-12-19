### 解题思路
1、直接用字符串容易复制，用列表还得自己复制；
2、如果是叶子结点，才会append到结果；
3、递归的参数中，需要带上全局的结果，以及当前遍历的结果；
4、path应该是在处理左右子树之前，做分隔符的拼接

### 代码

```python3
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        result_list = []
        self._dfs(root, "", result_list)

        return result_list

    def _dfs(self, root, path: str, result_list: List):
        """
        node_list: single node list
        reslt_list: final list
        """
        if not root:
            return ""

        path += str(root.val)
        if not root.left and not root.right:
            result_list.append(path)

        path += "->"
        if root.left:
            self._dfs(root.left, path, result_list)
        if root.right:
            self._dfs(root.right, path, result_list)
```