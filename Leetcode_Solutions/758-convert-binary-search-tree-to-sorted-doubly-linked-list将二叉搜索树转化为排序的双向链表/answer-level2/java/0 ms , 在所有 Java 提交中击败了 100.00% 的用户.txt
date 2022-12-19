### 解题思路
此处撰写解题思路

### 代码

```java
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
    public Node treeToDoublyList(Node root) {
        if(root == null) {
            return root;
        }
        Node lHead = treeToDoublyList(root.left);
        Node rHead = treeToDoublyList(root.right);
        Node head = (lHead != null ? lHead : root);
        Node last = (rHead != null ? rHead.left : root);
        if(lHead != null) {
            lHead.left.right = root;
            root.left = lHead.left;
        }
        if(rHead != null) {
            root.right = rHead;
            rHead.left = root;
        }
        head.left = last;
        last.right = head;
        return head;
    }
}
```