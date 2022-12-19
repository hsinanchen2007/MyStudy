### 解题思路
1. 中序遍历二叉搜索树
2. 如果节点val > L && val < R 则保留，否则舍弃
![image.png](https://pic.leetcode-cn.com/0dc9123b597bcc794791ca249f1c881ec298d7d8ca877e76fd1a335d1c323c9e-image.png)

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
    public TreeNode trimBST(TreeNode root, int L, int R) {
       if (root == null) {
            return null;
        }
        if (root.val < L) {
            return trimBST(root.right, L, R);
        } else if (root.val > R) {
            return trimBST(root.left, L, R);
        } else {
            root.left = trimBST(root.left, L, R);
            root.right = trimBST(root.right, L, R);
            return root;
        }
    }
}
```