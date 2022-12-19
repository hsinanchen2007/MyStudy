- 根据题目描述，树中任何节点的右子节点若存在一定有左子节点，因此思路是向左遍历树进行转化；
- 规律是：左子节点变父节点；父节点变右子节点；右子节点变父节点。
- 对于某节点`root`，修改`root.left`，`root.right`之前，需要将三者都存下来：
  - `root.left`是下一轮递归的主节点；
  - `root`是下一轮递归`root`的`root.right`；
  - `root.right`是下一轮递归`root`的`root.left`。
- 返回parent。



```python []
class Solution:
    def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
        parent = parent_right = None
        while root:
            root_left = root.left
            root.left = parent_right
            parent_right = root.right
            root.right = parent
            parent = root
            root = root_left
        return parent
```
```java []
class Solution {
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        TreeNode parent = null, parent_right = null;
        while(root != null){
            TreeNode root_left = root.left;
            root.left = parent_right;
            parent_right = root.right;
            root.right = parent;
            parent = root;
            root = root_left;
        }
        return parent;
    }
}
```