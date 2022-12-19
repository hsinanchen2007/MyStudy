### 解题思路
如果当前节点深度等于最大深度，相加
如果当前节点深度大于最大深度，重置sum
如果当前节点深度小于最大深度，继续向下

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
    private int sum=0;
    private int deep=0;
    public int deepestLeavesSum(TreeNode root) {
        helper(root,0);
        return sum;
    }
    private void helper(TreeNode node,int index){
        if (node==null)
            return;
        if (index==deep)
            sum += node.val;
        else if (index>deep){
            sum=node.val;
            deep=index;
        }
        helper(node.left,index+1);
        helper(node.right,index+1);
    }
}
```