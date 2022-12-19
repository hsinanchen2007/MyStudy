
毋宁说，直接上代码，官方优化了一下，这个看着更直观。
Java
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
    private TreeNode root = null;
    private int[] preorder;
    private int[] inorder;
    private int idxPreorder = 0;
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
         this.preorder = preorder;
         this.inorder = inorder;
         return createTree(0,inorder.length);
    }
    private TreeNode createTree(int idxLeft, int idxRight) {
        // if there is no elements to construct subtrees
    if (idxLeft == idxRight) {
      return null;
    }

    // pick up pre_idx element as a root
    int root_val = preorder[idxPreorder];
    TreeNode root = new TreeNode(root_val);
    // recursion 
    idxPreorder++;
    int index = 0;
    for(int i=0;i<inorder.length;i++)
    {
        if(inorder[i] == root_val) {
            index = i;
            break;
        }
    }
    // build left subtree
    root.left = createTree(idxLeft, index);
    // build right subtree
    root.right = createTree(index + 1, idxRight);
    return root;
    }
    
}
```
