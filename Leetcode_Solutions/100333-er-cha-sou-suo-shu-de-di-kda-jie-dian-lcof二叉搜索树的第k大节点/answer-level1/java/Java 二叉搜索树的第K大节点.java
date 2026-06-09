### 解题思路
根据二叉搜索树特点，中序遍历为升序，因此需要与中序遍历逆序返回第K个。
因此递归中序遍历处理root.left变更为root.right即可，left和right处理顺序交换。

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
    private int result = -1; // 定义全局变量，存储递归中结果
    public int kthLargest(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }
        count = k;
        func(root);
        return result;
    }

    private void func(TreeNode root) {
        if (root == null) {
            return;
        }
        // 因为是二叉搜索树的第K大，因此直接从最右开始
        if (root.right != null) {
            func(root.right);
        }
        count--;
        if (count == 0) {
            result = root.val;
            return;
        }

        func(root.left);
    }
}
```