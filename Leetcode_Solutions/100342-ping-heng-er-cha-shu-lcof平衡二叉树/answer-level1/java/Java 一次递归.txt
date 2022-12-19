### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/244bee3f08f299ed0a63e2c72111b891b20e35defe9c804af479d64dab4e131a-image.png)

判断是否平衡二叉树转化为
1.空树
2.左右子树深度差<=1
3.所有子树的左右子树深度差<=1

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
    //1.空树，2.树深度不为-1
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        int deep = getTreeDeep(root);
        return deep != -1;
    }

    /**
     * 获取子树深度，深度差大于1时，返回-1，否则返回正常树深度
     */
    private int getTreeDeep(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftDeep = getTreeDeep(root.left);
        if (leftDeep < 0) {
            return leftDeep;
        }
        int rightDeep = getTreeDeep(root.right);
        if (rightDeep < 0) {
            return rightDeep;
        }
        if (Math.abs(leftDeep - rightDeep) > 1) {
            return -1;
        }
        return Math.max(leftDeep, rightDeep) + 1;
    }
}
```