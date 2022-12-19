### 解题思路
> 核心思想，获取有序的数据，然后构造平衡二叉树；直接对原来的树排序复杂度比较高；

### 代码

```python3
class Solution:
    def tree_to_array(self, root, values):
        if root is None:
            return
        if root.left is not None:
            self.tree_to_array(root.left, values)
        values.append(root.val)
        if root.right is not None:
            self.tree_to_array(root.right, values)

    def build_balance_tree(self, values):
        if not values:
            return None
        middle = len(values) // 2
        root = TreeNode(values[middle])
        root.left = self.build_balance_tree(values[:middle])
        root.right = self.build_balance_tree(values[middle+1:])
        return root

    def balanceBST(self, root: TreeNode) -> TreeNode:
        values = []
        self.tree_to_array(root, values)
        return self.build_balance_tree(values)
```

- 本地用例用到的辅助函数（用于构造用例和检查结果）：
``` python3
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def creat_tree(data: List):
    if not data:
        return None
    count = 0
    root = TreeNode(data[count])
    count += 1

    # 标准化, [1,2] => [1,2,None]
    if len(data) % 2 == 0:
        data.append(None)
    queue = [root]
    while queue:
        node = queue.pop(0)
        if count >= len(data):
            break
        left, right = data[count:count + 2]
        if left is not None:
            node.left = TreeNode(left)
            queue.append(node.left)
        if right is not None:
            node.right = TreeNode(right)
            queue.append(node.right)
        count += 2

    return root


def tree_to_list(root):
    q = [root]
    ans = []
    while q:
        curr = q.pop(0)
        if curr is None:
            ans.append(None)
            continue
        ans.append(curr.val)
        q.append(curr.left)
        q.append(curr.right)
    return ans
```

# 运行效果
```
执行用时 :268 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :20 MB, 在所有 Python3 提交中击败了100.00%的用户
```