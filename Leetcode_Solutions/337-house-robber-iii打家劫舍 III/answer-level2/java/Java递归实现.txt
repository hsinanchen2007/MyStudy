这个问题用递归来做理解还是比较简单的：
对于当前节点我先判断它是不是null：
    是的话直接返回0；
    不是的话有两种选择：
        1、我取当前节点的值，然后跳过子节点，进入到孙子节点。（要判断子节点是否存在）
        2、我不取当前节点的值，直接进入到两个子节点。
        对以上两种情况我取最大值返回，得到的就是答案。

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
    public int rob(TreeNode root) {
        if(root==null)return 0;
        else{
            int t=root.val;
            TreeNode l=root.left;
            TreeNode r=root.right;
            if(l!=null)t+=rob(l.left)+rob(l.right);
            if(r!=null)t+=rob(r.left)+rob(r.right);
            return Math.max(t,rob(l)+rob(r));
        }
    }
}
```
