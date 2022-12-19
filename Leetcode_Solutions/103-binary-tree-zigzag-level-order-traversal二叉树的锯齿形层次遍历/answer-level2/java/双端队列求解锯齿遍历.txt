### 解题思路
参考[102. 二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

队列改为双端队列，根据要求的方向，隔层调整为LIFO或LOFI

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
    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<>();
        if (root == null) {
            return levels;
        }
        Deque<TreeNode> deque = new LinkedList<>();
        deque.add(root);
        int level = 0;

        //遍历方向需隔层反转
        boolean reverse = true;
        while (deque.size() > 0) {
            levels.add(new ArrayList<>());
            int queueSize = deque.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode node;
                if (reverse) {
                    //LIFO后进先出(先left再right)
                    node = deque.removeFirst();
                    if (node.left != null) {
                        deque.addLast(node.left);
                    }
                    if (node.right != null) {
                        deque.addLast(node.right);
                    }
                } else {
                    //FILO先进后出（先right再left）
                    node = deque.removeLast();
                    if (node.right != null) {
                        deque.addFirst(node.right);
                    }
                    if (node.left != null) {
                        deque.addFirst(node.left);
                    }
                }
                levels.get(level).add(node.val);
            }
            reverse = !reverse;
            level++;
        }
        return levels;
    }
}
```