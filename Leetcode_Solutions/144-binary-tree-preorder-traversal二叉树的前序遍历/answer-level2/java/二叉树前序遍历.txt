### 解题思路
前序，中序，后序这个必须要掌握的。很多题目的基础。

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

    public void preorder(TreeNode node){
        if(node == null)
            return;
        list.add(node.val);
        preorder(node.left);
        preorder(node.right);
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        preorder(root);
        return list;
    }
}
```