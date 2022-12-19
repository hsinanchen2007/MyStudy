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
    Set<Integer> set = new HashSet<>();
    
    public boolean isUnivalTree(TreeNode root) {
        if(root == null) {
            return true;
        }
        
        set.add(root.val);
        if(set.size() > 1) {
            return false;
        }
        
        return isUnivalTree(root.left) && isUnivalTree(root.right);
    }
}
```