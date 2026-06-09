### 解题思路
在 BFS 的时候记录当前节点与它的父节点

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
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(root, null));
        while (!queue.isEmpty()) {
            Node xNode = null;
            Node yNode = null;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.poll();
                TreeNode currNode = node.currNode;
                if (currNode.val == x) xNode = node;
                if (currNode.val == y) yNode = node;

                if (currNode.left != null) queue.add(new Node(currNode.left, currNode));
                if (currNode.right != null) queue.add(new Node(currNode.right, currNode));
            }
            if (xNode != null && yNode != null && xNode.parentNode != yNode.parentNode) {
                return true;
            }
        }
        return false;
    }

    class Node {
        TreeNode currNode;
        TreeNode parentNode;

        Node (TreeNode currNode, TreeNode parentNode) {
            this.currNode = currNode;
            this.parentNode = parentNode;
        }
    }
}
```