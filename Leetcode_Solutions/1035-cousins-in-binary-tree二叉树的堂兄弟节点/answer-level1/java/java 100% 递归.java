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
    int xdepth = -1;
    int ydepth = -1;
    TreeNode xParent = null;
    TreeNode yParent = null;
    public boolean isCousins(TreeNode root, int x, int y) {
        if(root==null){
            return false;
        }
        getdepth(root,x,y,0,null);
        return xdepth==ydepth&&xParent!=yParent;
    }

    private void getdepth(TreeNode root, int x,int y, int currentIndex,TreeNode parent){
        if(root==null){
            return;
        }
        if(root.val==x){
            xdepth = currentIndex;
            xParent = parent;
        }
        if(root.val==y){
            ydepth = currentIndex;
            yParent=parent;
        }
        ++currentIndex;
        getdepth(root.left,x,y,currentIndex,root);
        getdepth(root.right,x,y,currentIndex,root);
        
    }
}
```
