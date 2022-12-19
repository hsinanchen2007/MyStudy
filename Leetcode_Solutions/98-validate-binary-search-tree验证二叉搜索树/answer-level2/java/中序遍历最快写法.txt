二叉搜索树根据中序遍历的方式就会得到一个有序数组，所以只要保证当前遍历的节点值比上一个节点值大就可以。

```
class Solution {
    Integer maxValue;
    public boolean isValidBST(TreeNode root) {
        if (root == null){
            return true;
        }
        if (root.left != null && !isValidBST(root.left)){
            return false;
        }
        if (maxValue != null && maxValue >= root.val){
            return false;
        }
        maxValue = root.val;
        if (root.right != null && !isValidBST(root.right)){
            return false;
        }
        return true;
    }
}
```
