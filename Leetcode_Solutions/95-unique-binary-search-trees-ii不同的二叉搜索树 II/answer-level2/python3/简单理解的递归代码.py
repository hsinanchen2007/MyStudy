### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0: return []

        def get_tree(nums) -> List[TreeNode]:
            if len(nums) == 0:  # 要放个None以防没有数据，就不能遍历了
                return [None]
            if len(nums) == 1:
                return [TreeNode(nums[0])]

            all_trees = []
            for i in range(len(nums)):
                left_tree = get_tree(nums[:i])
                right_tree = get_tree(nums[i + 1:])
                for l in left_tree:
                    for r in right_tree:
                        head = TreeNode(nums[i])
                        head.left = l
                        head.right = r
                        all_trees.append(head)

            return all_trees

        nums = [i + 1 for i in range(n)]
        return get_tree(nums)



```