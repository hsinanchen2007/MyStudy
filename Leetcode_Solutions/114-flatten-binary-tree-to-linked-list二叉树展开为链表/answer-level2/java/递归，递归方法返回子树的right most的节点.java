对于任意子树来讲，通过递归将左子树flatten（返回左子树flatten后尾节点或者说最右侧的节点），然后将右子树flatten（返回右子树flatten后尾节点或者说最右侧的节点），将flatten后的左子树尾节点指向flatten后的右子树，再将root的右节点指向flatten后的左子树。执行完以上步骤后，当前子树就被flatten了，最后返回子树flatten后的尾节点。

```
class Solution {
        public void flatten(TreeNode root) {

            doFlatten(root);

        }

        // 返回flatten后的尾节点(或者说right most的节点)
        private TreeNode doFlatten(TreeNode subRoot) {

            if (subRoot == null) {
                return null;
            }


            // 得到flatten后的左子树的尾节点
            TreeNode tailOfLeft = doFlatten(subRoot.left);

            // 得到flatten后的右子树的尾节点
            TreeNode tailOfRight = doFlatten(subRoot.right);
            if (tailOfLeft != null) {
                tailOfLeft.right = subRoot.right;
                subRoot.right = subRoot.left;

                subRoot.left = null;
            }


            return tailOfRight == null ? (tailOfLeft == null ? subRoot: tailOfLeft) : tailOfRight;
        }
    }
```
