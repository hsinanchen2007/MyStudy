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
class Solution {

    Node head = null;
    Node tail = null;
    Node pre = null;
    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        dfs(root);
        head.left = tail;
        tail.right = head;
        // System.out.println(String.format("head %s %s %s", head, head.left, head.right));
        // System.out.println(String.format("tail %s %s %s", tail, tail.left, tail.right));
        return head;
    }

    
    void dfs(Node node) {
        if (node == null) {
            return;
        }
        dfs(node.left);
        if (head == null) {
            head = node;
        } if (pre != null) {
            pre.right = node;
            node.left = pre;
        }
        pre = node;
        tail = node;

        dfs(node.right);
        
    }










}
```
