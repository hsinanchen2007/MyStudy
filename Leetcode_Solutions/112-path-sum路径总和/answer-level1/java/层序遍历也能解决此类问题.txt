### 解题思路
一层层遍历，在记录TreeNode的同时，新开一个队列记录减掉的值，判断是叶子节点，且减掉的值最后为零的话即为满足条件的。

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
        public boolean hasPathSum(TreeNode root, int sum) {
            if (root == null) {
                return false;
            }
            Queue<TreeNode> node = new LinkedList<>();
            Queue<Integer> value = new LinkedList<>();
            node.add(root);
            value.add(sum - root.val);
            while (!node.isEmpty()) {
                int size = node.size();
                for (int i = 0; i < size; i++) {
                    TreeNode treeNode = node.poll();
                    int sumTmp = value.poll();
                    if (treeNode.left != null) {
                        node.add(treeNode.left);
                        value.add(sumTmp - treeNode.left.val);
                    }
                    if (treeNode.right != null) {
                        node.add(treeNode.right);
                        value.add(sumTmp - treeNode.right.val);
                    }
                    if (treeNode.right == null && treeNode.left == null) {
                        if (sumTmp == 0) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
}
```