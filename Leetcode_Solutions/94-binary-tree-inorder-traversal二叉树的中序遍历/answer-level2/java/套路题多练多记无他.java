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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> lst = new ArrayList<Integer>();
        helper(root,lst);
        return lst;
    }
    public void helper(TreeNode node,List<Integer> lst) {
        if(node == null) return ;
        if(node.left != null) {
            helper(node.left,lst);
            
        }
        lst.add(node.val);

        if(node.right != null) {
            helper(node.right,lst);
        }

       
    }
}
```