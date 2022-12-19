### 解题思路
如果要删除的节点就是树根，从右子树取最小值作为新的根，并在右子树中删除该值
如果要删除的节点不是树根，判断它在左子树还是右子树，并对该子树进行同样的操作。

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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) {
            return null;
        }
        if(key < root.val) {
            root.left = deleteNode(root.left, key);
            return root;
        }
        if(key > root.val) {
            root.right = deleteNode(root.right, key);
            return root;
        }
        if(root.right != null) {
            TreeNode rightMinNode = root.right;
            TreeNode rightMinFather = root;
            while(rightMinNode.left != null) {
                rightMinFather = rightMinNode;
                rightMinNode = rightMinNode.left;
            }
            root.val = rightMinNode.val;
            if(rightMinFather == root) {
                root.right = rightMinNode.right;
            }
            else {
                rightMinFather.left = rightMinNode.right;
            }
            return root;
        }
        else {
            return root.left;
        }
    }
}
```