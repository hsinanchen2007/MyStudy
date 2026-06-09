### 解题思路
此题只需直到左右子的左叶子结点即可。
注意：getSum里的参数，对于递归左子树的时候flag要设置为true，因为左子树有可能是左叶子节点。
对于递归右子树是flag要设置为false，因为对于根节点的右子树来说，不可能是左子叶节点。

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
    private int sum=0;
    public int sumOfLeftLeaves(TreeNode root) {
        getSum(root,false);
        return sum;
    }
    public void getSum(TreeNode root,boolean falg){
        if(root!=null){
            if(falg&&root.left==null&&root.right==null){
                sum+=root.val;
            }else{
                getSum(root.left,true);
                getSum(root.right,false);
            }
        }
    }
}
```