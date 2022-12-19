### 解题思路
从头到尾遍历每个数字，处理以下两种情况，将每个数字插入到树中，插入时有两种情况：
1：数字大于root，则吧当前数字当成root，已有的树作为root的左子树
2：数字小于root，则吧当前数字插入到当前root的右子树（插入右子树时同样处理这两种情况）

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
        /**
     * Runtime: 2 ms, faster than 99.75% of Java online submissions for Maximum Binary Tree.
     * Memory Usage: 39.2 MB, less than 82.61% of Java online submissions for Maximum Binary Tree.
     * @param nums
     * @return
     */
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            root = insert(root, nums[i]);
        }
        return root;
    }
    
    private TreeNode insert(TreeNode root, int num) {
        if (root == null) {
            return new TreeNode(num);
        }
        if (num > root.val) {
            TreeNode temp = new TreeNode(num);
            temp.left = root;
            root = temp;
        } else {
            root.right = insert(root.right, num);
        }
        return root;
    }
}
```