### 解题思路
1. 维护一个全局变量，然后从右开始中序遍历。在每一个根上都加上当前的累加值。
2. 就是先遍历右孩子，再遍历根，在遍历左孩子。全局变量也先有右孩子值，再有根值，最后有左孩子值。

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
    private int num = 0;
    public TreeNode convertBST(TreeNode root) {
        if(root == null) return null;  
        convertBST(root.right);
        root.val += num;
        num = root.val;
        convertBST(root.left);
        return root;
    }
}
```