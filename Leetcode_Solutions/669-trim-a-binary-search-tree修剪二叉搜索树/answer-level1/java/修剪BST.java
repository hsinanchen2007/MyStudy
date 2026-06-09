### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        TreeNode Base = new TreeNode(L);
        Base.left = root;// 保证剪完的节点在左边
        Base.right = null;
        DeleteL(root, L, Base);
        Base.right = Base.left;//保证剪完的节点在右边
        Base.left = null;
        DeleteR(Base.right, R, Base);
        return Base.right;
    }
    public void DeleteL(TreeNode root, int L, TreeNode parent){
        if(root == null){
            return;
        }
        if(root.val < L){
            parent.left = root.right;
            DeleteL(root.right, L, parent);
        }
        else{
            DeleteL(root.left, L, root);
        }
    }
    public void DeleteR(TreeNode root, int R, TreeNode parent){
        if(root == null){
            return;
        }
        if(root.val > R){
            parent.right = root.left;
            DeleteR(root.left, R, parent);
        }
        else{
            DeleteR(root.right, R, root);
        }
    }
}
```
对于以L为左边界修剪，在val小于L时，则L的左子树可以直接抛弃，继续遍历右子树，对于val大于等于L事，则还需对L的左子树遍历，右子树已经不需要考虑了