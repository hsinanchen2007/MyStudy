### 解题思路
基础

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
    List<Integer> list = new ArrayList<>();

    public void postorder(TreeNode node){
        if(node == null)
            return;
        postorder(node.left);
        postorder(node.right);
        list.add(node.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {
        postorder(root);
        return list;
    }
}
```