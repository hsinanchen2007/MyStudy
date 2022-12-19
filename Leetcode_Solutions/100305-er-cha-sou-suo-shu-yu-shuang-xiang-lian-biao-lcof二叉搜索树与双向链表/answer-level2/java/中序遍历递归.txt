说明后续再补充
```
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
public class Solution {
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        ReturnType res = inorder(root);
        res.left.left = res.right;
        res.right.right = res.left;
        return res.left;
    }

    class ReturnType {
        Node left;
        Node right;

        public ReturnType(Node left, Node right) {
            this.left = left;
            this.right = right;
        }
    }

    private ReturnType inorder(Node root) {
        if (root == null) {
            return new ReturnType(null, null);
        }
        ReturnType preResult = inorder(root.left);
        Node pre = preResult.right;
        if (pre != null) {
            root.left = pre;
            pre.right = root;
        }
        ReturnType nextResult = inorder(root.right);
        Node next = nextResult.left;
        if (next != null) {
            root.right = next;
            next.left = root;
        }
        return new ReturnType(preResult.left == null ? root : preResult.left, nextResult.right == null ? root : nextResult.right);
    }
}
```
