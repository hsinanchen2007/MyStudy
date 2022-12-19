```
class Solution {
    public int kthLargest(TreeNode root, int k) {
        int[] ret = new int[2] ;
        ret[0] = k ;
        kthLargest(root,ret) ;
        return ret[1] ;
    }

    public void kthLargest(TreeNode root  , int[] ret) {
        if (root == null)
            return ;

        if (root.right != null)
            kthLargest( root.right ,ret)  ;

        ret[0] -- ;
        if (ret[0] == 0) {
            ret[1] = root.val ;
            return ;
        }

        if (root.left != null)
            kthLargest(root.left ,ret)  ;
    }
}
```
