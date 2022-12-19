# 我们就求高度！就能够得到这题的答案！

设置一个全局变量代表结果是否为平衡二叉树。

对于每一个节点，当求出它左右子树高度的时候。

把左右子树高度差和1进行比较，若此时大于1，那么将全局变量设为false。

最后返回全局变量即可。

java 代码：

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
    public boolean isBalanced(TreeNode root) {
        
        height(root);
        return ans;
    }
    
    boolean ans = true;
    
    int height(TreeNode root)
    {
        if(root == null)
            return 0;
        int left = height(root.left);
        
        int right = height(root.right);
        
        if(Math.abs(left-right) > 1)
            ans = false;
        return 1 + Math.max(left,right);
    }
}
```
