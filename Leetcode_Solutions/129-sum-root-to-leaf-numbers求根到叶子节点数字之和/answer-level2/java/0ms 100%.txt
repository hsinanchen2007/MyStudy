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
    private int sum;
    public int sumNumbers(TreeNode root) {
        sum=0;
        if (root!=null)
            helper(root,0);
        return sum;
    }
    private void helper(TreeNode node, int current){
        if (node.left==null && node.right==null) {
            sum += current*10+node.val;
            return;
        }
        if (node.left!=null)
            helper(node.left,current*10+node.val);
        if (node.right!=null)
            helper(node.right,current*10+node.val);
    }
}
```