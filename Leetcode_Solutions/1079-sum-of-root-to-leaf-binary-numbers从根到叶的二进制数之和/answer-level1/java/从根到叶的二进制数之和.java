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
    public int sumRootToLeaf(TreeNode root) {
        //递归思路：就是把一个问题转化为与它类型相同的子问题。
        //如果树是空树，返回值肯定为0。如果只有根节点，那么 就是返回根节点的二进制之和。
        //否则就是将根节点的二进制数加到左右子树上，返回左右子树的二进制之和相加
        if(root==null)
            return 0;
        int mod=root.val%1000_000_007;
        if(root.left==null&&root.right==null)
            return mod;
        if(root.left!=null)
            root.left.val=root.left.val+(mod<<1);
        if(root.right!=null)
            root.right.val=root.right.val+(mod<<1);
        return (sumRootToLeaf(root.left)+sumRootToLeaf(root.right))%1000_000_007;
    }
}
```