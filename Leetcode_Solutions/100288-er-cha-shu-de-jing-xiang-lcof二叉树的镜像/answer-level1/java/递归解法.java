二叉树转换为其镜像二叉树后，其子树也转换为自身的镜像二叉树；

因此，从上而下，先交换根节点的左右节点，然后对其子树做同样的镜像操作。

```java
class Solution {
    public TreeNode mirrorTree(TreeNode root) {
         if(root == null || (root.left == null && root.right == null)){
            return root;
        }
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        mirrorTree(root.right);
        mirrorTree(root.left);
        return root;
    }
}
```
