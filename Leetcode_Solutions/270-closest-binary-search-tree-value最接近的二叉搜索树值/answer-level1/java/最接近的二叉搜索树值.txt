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
    public int closestValue(TreeNode root, double target) {
        //把这个target当做在二叉搜索树中需要搜索的节点.
        double minDiff=Double.MAX_VALUE;
        TreeNode closestNode=root;   //我们首先将根节点视为最近的节点。
        TreeNode node=root;
        while(node!=null)  //当不是空时
        {
            double diff=Math.abs(node.val-target);
            if(diff<minDiff){
                minDiff=diff;
                closestNode=node;
            }
            if(target>node.val)
            {
                node=node.right;
            }
            else if(target<node.val){
                node=node.left;
            }
            else
                return node.val;
        }
        return closestNode.val;
    }
}
```