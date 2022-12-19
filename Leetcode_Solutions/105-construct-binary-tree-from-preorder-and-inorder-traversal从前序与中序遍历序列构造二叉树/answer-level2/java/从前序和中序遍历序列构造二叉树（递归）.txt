这是一个递归问题，前序遍历是ceter-left-right的方式遍历，中序遍历是left-ceter-right（这里的ceter是指父节点，left，right是左右子树）。
因此，前序遍历的第一个数是父节点的值，由于树的各个节点值唯一，根据中序遍历，找到父节点所在的索引位置，就可以判断左子树，右子树了。同样的，对左，右子树分别进行这样的操作，就可以把原来的树进行补全了。

```
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length == 0){
            return null;
        }
        TreeNode resTree = new TreeNode(0);
        resTree.val = preorder[0];
        int i = 0;
        for(; i< inorder.length; i++){
            if(inorder[i] == preorder[0]){
                break;
            }
        }
        resTree.left = buildTree(Arrays.copyOfRange(preorder, 1, 1+i),
                                 Arrays.copyOfRange(inorder, 0, i));
        resTree.right = buildTree(Arrays.copyOfRange(preorder, 1+i, preorder.length),
                                 Arrays.copyOfRange(inorder, 1+i, inorder.length));
        return resTree;
    }
}
```
