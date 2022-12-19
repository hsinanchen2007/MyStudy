两次dfs, 第一次建立父子节点关系的图(用字典维护)，第二次计算长度。超过80%
如代码逻辑冗余，又可以优化的地方，请各位大大指正，不胜感激！

```ruby
class Solution:
    
    def __init__(self):
        # 每个节点的值唯一,不会出现重复的key
        self.node_dict = {}
        self.finished = False
        self.visited = set()

    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        if not self.finished:
            self.calculate_dict(root)
            self.finished = True
        if not target:
            return []
        if target.val in self.visited:
            return []
        else:
            self.visited.add(target.val)
        if not self.node_dict.get(target.val, None) and K == 0:
            return [target.val]
        if not target.left and not target.right and not self.node_dict.get(target.val, None) and K != 0:
            return []
        val_list = []
        left_list = []
        right_list = []
        parent_list = []
        if K == 0:
            val = target.val
            val_list.append(val)
        if target.left:
            left_list = self.distanceK(root, target.left, K-1)
        if target.right:
            right_list = self.distanceK(root, target.right, K-1)
        if self.node_dict.get(target.val, None):
            parent_list = self.distanceK(root, self.node_dict[target.val], K-1)
        return val_list + left_list + right_list + parent_list
            
    def calculate_dict(self, root):
        if not root:
            return
        if not root.left and not root.right:
            return
        if root.left:
            self.calculate_dict(root.left)
            self.node_dict[root.left.val] = root
        if root.right:
            self.calculate_dict(root.right)
            self.node_dict[root.right.val] = root
```