### 解题思路
逐层递归，达到最深处的第一个值返回即可

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
    private int maxDeep=0;
    private int value;
    public int findBottomLeftValue(TreeNode root) {
        value=root.val;
        helper(root,0,0);
        return value;
    }
    private void helper(TreeNode node,int depth,int pre){
        if (node==null){
            if (depth>maxDeep){
                maxDeep=depth;
                value=pre;
            }
            return;
        }
        helper(node.left,depth+1,node.val);
        helper(node.right,depth+1,node.val);
    }
}
```