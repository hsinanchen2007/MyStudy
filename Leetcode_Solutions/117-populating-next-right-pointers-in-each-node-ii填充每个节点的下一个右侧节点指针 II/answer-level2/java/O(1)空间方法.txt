```java
class Solution {
    public static Node connect(Node root) {
        if (root == null) {
            return null;
        }
        Node pre = root;
        Node cur;
        while (pre != null) {
            cur = pre;
            // 寻找cur这一层中的子节点的next
            while (cur != null) {
                // 寻找左子节点的next
                if (cur.left != null) {
                    if (cur.right != null) {
                        cur.left.next = cur.right;
                    } else {
                        // 将cur.left右边的第一个结点作为next
                        cur.left.next = findNext(cur.next);
                    }
                }
                // 寻找右子节点的next
                if (cur.right != null) {
                    // 将cur.right右边的第一个结点作为next
                    cur.right.next = findNext(cur.next);
                }
                cur = cur.next;
            }
            // 更新pre为下一层中的最左端结点
            pre = findNext(pre);
        }
        return root;
    }

    /**
     * 寻找最左结点为next结点
     */
    private static Node findNext(Node node) {
        while (node != null) {
            if (node.left != null) {
                return node.left;
            } else if (node.right != null) {
                return node.right;
            }
            node = node.next;
        }
        return null;
    }
}
```