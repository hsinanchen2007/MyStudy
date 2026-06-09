## bfs 实现（java）

使用一个队列进行层次遍历即可。

import java.util.LinkedList;
import java.util.Queue;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Node {
    public TreeNode node;
    public int val;
}

class Solution {
    public int sumNumbers(TreeNode root) {
        Queue<Node> queue = new LinkedList<Node>();
        int sum = 0;
      if (root != null) {
        Node node = new Node();
        node.node = root;
        node.val = root.val;
        ((LinkedList<Node>) queue).push(node);
      }

        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            TreeNode ct = curr.node;
            if (ct.left == null && ct.right == null) {
                sum += curr.val;
            }
            Node next;
            if (ct.left != null) {
                next = new Node();
                next.val = curr.val * 10 + ct.left.val;
                next.node = ct.left;
                ((LinkedList<Node>) queue).push(next);
            }
            if (ct.right != null) {
                next = new Node();
                next.val = curr.val * 10 + ct.right.val;
                next.node = ct.right;
                ((LinkedList<Node>) queue).push(next);
            }
        }
        return sum;
    }
}