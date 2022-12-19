### 解题思路
1.在递归的基础上记录上一层计算过的数据来减少时间复杂度。
2.树形dp方法主要采用“从叶节点到根节点“，故每一层的数据只于下一层的有关系，记录每一层偷与不偷的金额最大值。

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
    public int rob(TreeNode root) {
        //暴力递归
        // if(root==null) return 0;
        // TreeNode left=root.left,right=root.right;
        // int t=root.val,var1=0,var2=0;
        // if(left!=null) var1=rob(left.left)+rob(left.right);
        // if(right!=null) var1+=rob(right.left)+rob(right.right);
        // var2=rob(left)+rob(right);
        // return Math.max(t+var1,var2);
        //动态规划()
        //思路：定义一个数组res,长度为2,res[0]表示不抢该节点可获得最大值,res[1]表示抢劫该节点可获得最大值
        int[] res=helper(root);
        return Math.max(res[0],res[1]);
    }
    public int[] helper(TreeNode root){
        if(root==null) return new int[2];
        int[] left=helper(root.left);
        int[] right=helper(root.right);
        int[] res=new int[2];
        res[0]=Math.max(left[0],left[1])+Math.max(right[0],right[1]);//计算不抢劫当前根节点可获得的最大金额(那么其左右子树可以随便抢)
        res[1]=root.val+left[0]+right[0];//计算若抢劫根节点可获得的最大金额(此时,其左右子树的根节点不能被抢)
        return res;
    }
}
```