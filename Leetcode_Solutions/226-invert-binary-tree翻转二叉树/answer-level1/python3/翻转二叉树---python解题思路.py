老样子套递归模板三部曲

1.**递归结束的条件** 节点为空就结束了，这里注意题目运行为None的左右节点交换

2.**本次递归做什么操作** 交换root的左右节点

3.**返回什么** 当然是返回root节点啦

```python
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None: return root
        tem = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(tem)
        return root        
```

运行结果：

```
执行用时 :28 ms, 在所有 python3 提交中击败了98.73% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.58%的用户

执行用时 :28 ms, 在所有 python3 提交中击败了98.73% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.58%的用户

执行用时 :24 ms, 在所有 python3 提交中击败了99.80% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.58%的用户
```

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)