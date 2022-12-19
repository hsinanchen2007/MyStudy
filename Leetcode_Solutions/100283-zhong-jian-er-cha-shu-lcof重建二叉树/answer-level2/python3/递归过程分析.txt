### 解题思路
递归分析：
    - 递归的参数：根节点在前序遍历的索引`pre_root`；此根节点要构造的二叉树所包含在中序遍历中的左`in_left`、右`in_right`范围索引
    - 递归结束条件：此根节点要构造的二叉树为空，即`in_left>in_right`
    - 递归过程：
        - 建立根节点
        - 找到根节点在中序遍历中的位置`in_root`
        - 建立左子树: `pre_root` = `pre_root+1`, `in_left` = `in_left`, `in_right` = `in_root-1`
        - 建立右子树: `pre_root` = `pre_root+1+in_root-in_left`, `in_left` = `in_root+1`, `in_right` = `in_right`

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder is None or len(preorder) == 0:
            return None
        self.hashmap = {}
        self.po = preorder
        for i in range(len(inorder)):
            self.hashmap[inorder[i]] = i
        
        return self.buildTreeCore(0, 0, len(inorder)-1)

    def buildTreeCore(self, pre_root, in_left, in_right):
        # 递归退出条件
        if in_left > in_right: return None
        # 递归过程
        root_node = TreeNode(self.po[pre_root])  # 建立根节点
        in_root = self.hashmap[self.po[pre_root]]  # 找到根节点在中序遍历中的位置
        root_node.left = self.buildTreeCore(pre_root+1, in_left, in_root-1)  # 建立左子树
        root_node.right = self.buildTreeCore(pre_root+1+in_root-in_left, in_root+1, in_right)  # 建立右子树
        return root_node

        
        
```