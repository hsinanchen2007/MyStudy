### 解题思路
递归+数组带出高度值

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
    public boolean isBalanced(TreeNode root) {
        int[] h = new int[1];
        return isBalanced(root, h);
    }
    public boolean isBalanced(TreeNode root, int[] height) {
        if (root == null) {
            height[0] = 0;
            return true;
        }
        int[] lh = new int[1];
        int[] rh = new int[1];
        if (isBalanced(root.left, lh) &&
                isBalanced(root.right, rh) &&
                Math.abs(lh[0]-rh[0])<=1) {
            height[0] = 1+Math.max(lh[0], rh[0]);
            return true;
        } else {
            return false;
        }
    }

}
```
![image.png](https://pic.leetcode-cn.com/486a845ea51d1143225ef8d94fc1d7ce63cf18d8711f45e978d1a961873c097d-image.png)
