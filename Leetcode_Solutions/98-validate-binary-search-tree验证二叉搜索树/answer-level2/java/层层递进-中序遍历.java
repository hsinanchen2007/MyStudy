### 解题思路
1. 根据二叉搜索树特性，如果中序遍历二叉树，会得到一组升序排列的树
2. 只需要比较前一个和当前节点值是否是升序即可
![image.png](https://pic.leetcode-cn.com/6ec4765de666f93f0af740b9b2d3f51e0a015516666a60caacbeb9f1685d9539-image.png)

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
    Integer pre = null;
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (isValidBST(root.left)) {
            if (pre == null || root.val > pre) {
                pre = root.val;
                return isValidBST(root.right);
            }
        }
        return false;
    }
}
```