### 解题思路
使用一个长度为1的数组保存树的节点个数，将其作为参数传入递归函数中，便可以更新每次递归的值
递归中可以写任何树的遍历方法，每次遍历一个节点，都要更新数组的值

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
    public int countNodes(TreeNode root) {
        int[] res = new int[1];
        res[0] = 1;  // 算上跟节点的一个
        count(root, res);  // 将数组作为参数传入递归，可以更新每次递归后的值
        return res[0];
    }

    public void count(TreeNode root, int[] res) {
        if (root == null) {
            res[0]--;  // 当遍历到空节点时，记得减去已经加上的节点个数
            return;
        }
        if (root.left != null) {
            res[0]++;
            count(root.left, res);
        }
        if (root.right != null) {
            res[0]++;
            count(root.right, res);
        }
    }
}
```