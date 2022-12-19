### 解题思路
此处撰写解题思路

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

    //时间空间 0n
    //   public void flatte2(TreeNode root) {
    // 	if (root == null) return;
    // 	if (root.left != null) {
    //     	// 保留之前的right
    //     	TreeNode oldRight = root.right;
    //     	// 将left嫁接到right
    //     	root.right = root.left;
    //     	// 清空left
    //     	root.left = null;
    //     	// 将旧的right嫁接到root的最右下角
    //     	TreeNode rightMost = root;
    //         //拿到最right的点
    //     	while (rightMost.right != null) {
    //     		rightMost = rightMost.right;
    //     	}
    //         //嫁接成功
    //     	rightMost.right = oldRight;
    // 	}
    // 	flatten(root.right);
    // }

//非递归
     public void flatten(TreeNode root) {
     while (root != null) {
         if (root.left != null) {
             // 保留之前的right
             TreeNode oldRight = root.right;
             // 将left嫁接到right
             root.right = root.left;
             // 清空left
             root.left = null;
             // 将旧的right嫁接到root的最右下角
             TreeNode rightMost = root;
             while (rightMost.right != null) {
                 rightMost = rightMost.right;
             }
             rightMost.right = oldRight;
         }
         root = root.right;
     }
 }
}
```