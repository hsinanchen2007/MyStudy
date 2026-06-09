### 解题思路
二叉搜索树的中序遍历是升序排列，直接用较大数减较小数即可

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
    //初始化最小值
    private int min=Integer.MAX_VALUE;
    //记录前一个节点
    private TreeNode pre=null;
    public int getMinimumDifference(TreeNode root) {
        inOrder(root);
        return min;
    }

    //标准中序遍历写法
    public void inOrder(TreeNode root){
        if(root==null){
            return;
        }

        inOrder(root.left);
        if(pre!=null){
            //二叉搜索树的中序遍历是升序排列，直接用较大数减较小数即可
            min=Math.min(min,(root.val-pre.val));
        }
        //记录中序遍历的前一个节点
        pre=root;
        
        inOrder(root.right);
    }
}
```