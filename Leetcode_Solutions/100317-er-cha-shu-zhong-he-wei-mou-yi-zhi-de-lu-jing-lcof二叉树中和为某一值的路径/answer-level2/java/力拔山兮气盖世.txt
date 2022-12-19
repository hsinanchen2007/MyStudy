```
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>() ;
        pathSum(root , sum ,  0 , new ArrayList<Integer>() ,  ret ) ;
        return ret ;
    }

    public void pathSum(TreeNode node ,int sum , int pathSum ,List<Integer> path , List<List<Integer>> ret ) {
        if (node != null) {
            if ( (pathSum + node.val) == sum && node.left == null && node.right == null ) {
                path.add(node.val) ;
                ret.add(path) ;
            }
            if ( node.left != null) {
                List<Integer> pathNew = new ArrayList<>() ;
                pathNew.addAll(path) ;
                pathNew.add(node.val) ;
                pathSum( node.left , sum ,  pathSum + node.val , pathNew ,  ret ) ;
            }
            if ( node.right != null) {
                List<Integer> pathNew = new ArrayList<>() ;
                pathNew.addAll(path) ;
                pathNew.add(node.val) ;
                pathSum( node.right , sum ,  pathSum + node.val , pathNew ,  ret ) ;
            }
        }
    }
}
```
