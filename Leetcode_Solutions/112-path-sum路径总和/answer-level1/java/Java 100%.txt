### 解题思路

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
    public boolean flag = false; //记录是否有路径和为sum
    public boolean hasPathSum(TreeNode root, int sum) {
       helper(root,sum,0);
       return flag;
    }
    public void helper(TreeNode root, int sum, int presum)//presum记录根节点到当前节点前的路径和
    {
        if(root == null)
         return;
        if(root.left==null&&root.right==null)
        {
            if(presum+root.val==sum)//是叶子节点且之前的路径和加当前节点的值为sum，则标记找到节点
             {
                 flag=true;
                 return;
             }
            else return;
        }
        helper(root.left,sum,presum+root.val);
        helper(root.right,sum,presum+root.val);
        return;       
    }
}
```