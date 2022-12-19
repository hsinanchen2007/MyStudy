### 解题思路
递归法
首先注意到题目中的说明和对于root的给定，简化了很多特殊条件。

情况1：根节点就是目标，那么可能是一上来就为p或q的其中一个输入，或者是分别存在于左右子树当中，则需要自上向下遍历搜索。
（如p = 7,q = 8，这时root会遍历到这两个点，分别返回7、8，在对其进行判空，最后发现直接返回根节点）
情况2：非根节点为目标，那么可能是都存在于左子树或右子树当中，此时需要自上向下遍历搜索。直到满足了
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
 //说明：所有节点的值都是唯一的。
//       p、q 为不同节点且均存在于给定的二叉树中。
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
       //首先要检查当前的root情况，若为null就直接返回；
       //若为p、q则是满足最近公共节点为节点本身
       if(root == null || root == p || root == q)
            return root;
        
        //再利用递归从根节点开始，开始向下遍历每个节点（以下两步则为具体对每一个节点的左右子树查找），由上述if语句的返回值得到这两个节点的值
       TreeNode left = lowestCommonAncestor(root.left,p,q);
       TreeNode right = lowestCommonAncestor(root.right,p,q); 
       
       //对于left和right节点返回的情况，如果根节点的左子树/右子树找不到最近公共节点，那么就说明在右子树/左子树当中
       if(left == null)
            return right;
        
        if(right == null)
            return left;
        //如果上述两个情况都不符合 则说明根节点就是最近公共节点，直接返回
        return root;
    }
}
```