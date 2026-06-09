![image.png](https://pic.leetcode-cn.com/689ef4a62e821ba6dc843ab50eb026052b2c1c00227af8e6238b0c7f03f68ffd-image.png)
翻转树就是左右节点交换的过程，一层一层递归交换结点
```
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null) return null;
        TreeNode temp = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(temp);
        return root;
    
    }
}
```
函数的返回结果是当前的root，实现了root.left 和root.right之间的交换