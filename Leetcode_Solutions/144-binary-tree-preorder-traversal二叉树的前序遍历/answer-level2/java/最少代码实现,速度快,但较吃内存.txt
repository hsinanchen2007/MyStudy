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
    
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root != null){
            res.add(root.val);
            if(root.left != null) {
                res.addAll(preorderTraversal(root.left));
            }
            if(root.right != null) {
                res.addAll(preorderTraversal(root.right));
            } 
        }
        return res;
    }
}
```