### 解题思路
由于两个二叉树 `original` 和 `cloned` 的结构一样，对于 `original` 中的每个节点，都有一个在 `cloned` 中的对应节点，因此对两个二叉树做同步的广度优先搜索。当 `original` 中遇到一个节点与 `target` 相同时，`original` 中的对应节点即为要返回的节点。
由于此处判断的是节点引用本身，而不是节点值，因此该方法也适用于二叉树中有重复值的情况。

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
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        TreeNode copy = null;
        Queue<TreeNode> queue1 = new LinkedList<TreeNode>();
        Queue<TreeNode> queue2 = new LinkedList<TreeNode>();
        queue1.offer(original);
        queue2.offer(cloned);
        while (!queue1.isEmpty()) {
            TreeNode node1 = queue1.poll();
            TreeNode node2 = queue2.poll();
            if (node1 == target) {
                copy = node2;
                break;
            }
            TreeNode left1 = node1.left, right1 = node1.right;
            TreeNode left2 = node2.left, right2 = node2.right;
            if (left1 != null) {
                queue1.offer(left1);
                queue2.offer(left2);
            }
            if (right1 != null) {
                queue1.offer(right1);
                queue2.offer(right2);
            }
        }
        return copy;
    }
}
```