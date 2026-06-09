### 解题思路
循环，

如果接下来的元素比根节点小，保存到一个数组，作为右边的孩子
如果节点比root大， 作为新的root，原来的tree作为左节点

### 代码

```python3

class Solution:
    # 给定一个数组， 返回最大值，左边的数，右边的数
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        # 第一个元素
        tree = None
        less_nums = []
        for val in nums:
            if tree is None:
                tree = TreeNode(val)
            elif val < tree.val:
                less_nums.append(val)
            else:
                if less_nums:
                    tree.right = self.constructMaximumBinaryTree(less_nums)

                node = TreeNode(val)
                node.left = tree

                less_nums = []
                tree = node
        if less_nums:
            tree.right = self.constructMaximumBinaryTree(less_nums)

        return tree

```