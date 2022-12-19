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
    List<List<Integer>> leavesList = new ArrayList<>();
    public List<List<Integer>> findLeaves(TreeNode root) {
        if(root == null) {
            return leavesList;
        }
        while(root != null) {
            List<Integer> list = new ArrayList<>();
            root = helpFind(root, list);
            leavesList.add(list);
        }
        return leavesList;
    }
    private TreeNode helpFind(TreeNode root, List<Integer> list) {
        if(root == null) {
            return null;
        }
        if(root.right == null && root.left == null) {
            list.add(root.val);
            root = null;
            return root;
        }
        root.left = helpFind(root.left, list);
        root.right = helpFind(root.right, list);
        return root;
    }
}
```