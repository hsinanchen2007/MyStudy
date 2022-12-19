### 解题思路  返回值就是第二最小值，但是要判断左右节点值是否与根节点相等


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
    public int findSecondMinimumValue(TreeNode root) {
        if(root==null) return -1;
        if(root.left==null&&root.right==null)
            return -1;
        int leftValue=root.left.val,rightValue=root.right.val;
        if(root.val==leftValue) 
            leftValue=findSecondMinimumValue(root.left);
        if(root.val==rightValue) rightValue=findSecondMinimumValue(root.right);
        if(leftValue!=-1&&rightValue!=-1) return Math.min(leftValue,rightValue);
        return leftValue==-1?rightValue:leftValue;
    }
}
```