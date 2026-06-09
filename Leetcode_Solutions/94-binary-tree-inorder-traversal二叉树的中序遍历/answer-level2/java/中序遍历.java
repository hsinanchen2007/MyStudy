### 解题思路
中序遍历递归应该写烂了的把

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

    public void midorder(TreeNode root){
        if(root == null)
            return;
        midorder(root.left);
        list.add(root.val);
        midorder(root.right);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        midorder(root);
        return list;
    }
}
```