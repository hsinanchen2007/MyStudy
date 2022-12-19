```
# 思路： 构建一个二叉搜索树，左子树小于等于根节点，右子树大于根节点
#       节点内记录下标，所有左节点的个数，以及右侧小于该节点的总数
#       若插入节点小于等于当前节点，则当前节点的左节点总数+1
#       若插入节点大于当前节点，则当前节点的右侧小于该节点的总数=当前节点的左节点总数+1(当前节点)
#       最后深度遍历


class BST(object):
    def __init__(self, index, val):
        self.left = None
        self.right = None
        self.index = index
        self.val = val
        # 右侧小于该节点的总数
        self.count = 0
        # 左子树总数
        self.left_count = 0

    def insert(self, node):
        if node.val <= self.val:
            self.left_count += 1
            if not self.left:
                self.left = node
            else:
                self.left.insert(node)
        else:
            node.count += self.left_count + 1
            if not self.right:
                self.right = node
            else:
                self.right.insert(node)


class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        nums = nums[::-1]
        root = BST(0, nums[0])
        for i in range(1, len(nums)):
            root.insert(BST(i, nums[i]))
        ret = [0] * len(nums)

        def _dfs(root):
            if not root:
                return ret
            ret[root.index] = root.count
            _dfs(root.left)
            _dfs(root.right)
            return ret

        return _dfs(root)[::-1]
```