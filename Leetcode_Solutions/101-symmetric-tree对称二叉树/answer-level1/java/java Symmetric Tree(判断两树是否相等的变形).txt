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
    public boolean isSymmetric(TreeNode root) {
        if(root==null||(root.left==null&&root.right==null)) return true;
        //左子树
        TreeNode lrode=root.left;
        //右子树
        TreeNode rrode=root.right;
        //判断是否镜像对称
        return boolIsSymmetric(lrode,rrode);
    }
    
    public  Boolean boolIsSymmetric(TreeNode left,TreeNode right){
        //如果当前两个节点都为空,放回true
        if(left==null&&right==null) return true;
        //如果当前两个节点有切仅有一个为空,放回false
        if(left==null||right==null) return false;
        //如果两个节点的值不一样,放回false
        if(left.val!=right.val) return false;
        //最关键的一步,左子数从左子节点开始遍历,右子数从右子节点开始遍历
        return boolIsSymmetric(left.left,right.right)&&boolIsSymmetric(left.right,right.left);
    }
}
```