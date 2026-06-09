### 解题思路
1. 中序遍历，设置一个全局count计数，遍历到第k个位置时，返回结果

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
    private int count = 0;
    public int kthSmallest(TreeNode root, int k) {
        if(root == null) return 0;
        int left = kthSmallest(root.left, k);
        if(left != 0) return left;
        if(++count == k) return root.val;
        int right = kthSmallest(root.right, k);
        if(right != 0) return right;
        return 0;
    }
}
```