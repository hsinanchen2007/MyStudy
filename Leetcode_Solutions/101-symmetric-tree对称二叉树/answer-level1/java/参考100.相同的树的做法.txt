刚做完100.相同的树，再做这题，直接有了想法，对称二叉树可以看作根节点接着另两个树，让这两个树镜面相等（反正不是直接相等）
看了看题解，感觉思路有点偏😄
不难，直接放代码：
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
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        return isSameTree(root.left,root.right);
    }
    boolean isSameTree(TreeNode p, TreeNode q) {
        if(q == null && p == null){
            return true;
        }
        else if(q == null || p == null){
            return false;
        }
        else if(q.val != p.val){
            return false;
        }
        //isSameTree(p.left,q.right) && isSameTree(p.right,q.left)里参数要注意
        return isSameTree(p.left,q.right) && isSameTree(p.right,q.left);
    }
}
```


![image.png](https://pic.leetcode-cn.com/48ad0cec5b9821d9367799495fe59346691797bfed2eb46786f6a87d6c0a94b1-image.png)