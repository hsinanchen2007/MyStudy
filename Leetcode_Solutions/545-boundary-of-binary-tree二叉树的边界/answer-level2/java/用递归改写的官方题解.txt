### 解题思路
参考官方题解改写的实现：
1. 单独处理 root 节点；
2. 把左边枝干加到结果里；
3. 把所有叶子节点添加到结果里；
4. 最后添加右边枝干到结果里。

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

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        if (root == null) {
            return ans;
        }
        if (!isLeaf(root)) {
            ans.add(root.val);
        }
        leftTrunk(root.left, ans);
        addLeaves(root, ans);
        rightTrunk(root.right, ans);

        return ans;
    }

    private void leftTrunk(TreeNode root, List<Integer> ans) {
        if (root == null) {
            return;
        }
        if (!isLeaf(root)) {
            ans.add(root.val);
        }
        if (root.left != null) {
            leftTrunk(root.left, ans);
        } else {
            leftTrunk(root.right, ans);
        }
    }

    private void rightTrunk(TreeNode root, List<Integer> ans) {
        if (root == null) {
            return;
        }
        if (root.right != null) {
            rightTrunk(root.right, ans);
        } else {
            rightTrunk(root.left, ans);
        }
        if (!isLeaf(root)) {
            ans.add(root.val);
        }
    }

    private void addLeaves(TreeNode node, List<Integer> ans) {
        if (node == null) {
            return;
        }
        if (isLeaf(node)) {
            ans.add(node.val);
        } else {
            addLeaves(node.left, ans);
            addLeaves(node.right, ans);
        }
    }

    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
```