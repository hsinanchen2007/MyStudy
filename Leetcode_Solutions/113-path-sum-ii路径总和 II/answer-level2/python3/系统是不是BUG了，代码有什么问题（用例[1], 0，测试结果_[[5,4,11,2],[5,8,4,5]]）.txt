class Solution:
    path = 0
    path_sums = []
    paths = []

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return []
        if not root.left and not root.right:
            if root.val == sum:
                return [[root.val]]

        self._walk_in_tree(root, sum)

        return self.path_sums

    def _walk_in_tree(self, root: TreeNode, sum: int):
        """
        walk in the tree, to see if there are paths == sum
        1. if find paths return true
        2. if not return false even there is no paths
        :param root: tree entry
        :param sum: sum of the paths
        :return: true or false
        """
        self.path += root.val
        self.path_num = root.val
        self.paths.append(self.path_num)
        if self.path == sum:
            path_copy = self.paths[:]
            self.path_sums.append(path_copy)
            # return self.path_sums
        if root.left:
            self._walk_in_tree(root.left, sum)
        if root.right:
            self._walk_in_tree(root.right, sum)

        self.path -= root.val
        self.paths.pop()