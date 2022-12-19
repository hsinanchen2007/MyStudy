![image.png](https://pic.leetcode-cn.com/f9eda24d5fa123590bf22ab2277e5294c58dee6eaf58c6c8a8f5a3820b4d44af-image.png)

代码看上去复杂，实际上逻辑很简单，在递归的同时，判断是否已经找到`k`节点，
`def dfs(self, root):`函数返回的四个结果分别代表
`是否已经找到k节点`： `True` `、False`
`当前的最优结果`：如果已经找到`k`节点，则当前的最优结果是`k节点到叶子节点的距离`和`k节点经过它向上的公共父节点所得找到的最小叶子节点距离`两者中较小的那个
`向上返回的距离`：如果已经找到`k`节点，则返回`k`节点往上走的距离，如果没有找到`k`节点，则返回当前的叶子节点往上走的距离
`当前最优距离对应的节点`：用于计算返回值

```
class Solution:
    def findClosestLeaf(self, root: TreeNode, k: int) -> int:
      # isCommonPath, CommonPathLen, NonCommonPathLen, Node
      self.k = k
      _, _, _, res = self.dfs(root)
      return res.val

    def dfs(self, root):
      if not root: return False, 0, 1e9, None
      if not root.left and (not root.right):
        if root.val == self.k: return True, 0, 0, root
        else: return False, 0, 1, root
      left_state, left_true_len, left_non_true_len, left_node = \
        self.dfs(root.left)
      right_state, right_true_len, right_non_true_len, right_node = \
        self.dfs(root.right)
      if self.k == root.val:
        if left_non_true_len > right_non_true_len:
          return True, right_non_true_len, 1, right_node
        else: return True, left_non_true_len, 1, left_node
      else:
        if left_state:
          if left_true_len > left_non_true_len + right_non_true_len:
            return True, left_non_true_len + right_non_true_len, left_non_true_len + 1, right_node
          else:
            return True, left_true_len, left_non_true_len + 1, left_node
        elif right_state:
          if right_true_len > left_non_true_len + right_non_true_len:
            return True, left_non_true_len + right_non_true_len, right_non_true_len + 1, left_node
          else:
            return True, right_true_len, right_non_true_len + 1, right_node
        else:
          if right_non_true_len > left_non_true_len:
            return False, 0, left_non_true_len + 1, left_node
          else:
            return False, 0, right_non_true_len + 1, right_node
```
