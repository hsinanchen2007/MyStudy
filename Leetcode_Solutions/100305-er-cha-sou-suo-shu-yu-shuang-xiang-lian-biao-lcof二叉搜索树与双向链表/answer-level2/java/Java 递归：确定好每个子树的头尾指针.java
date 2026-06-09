中序遍历，理解了每个节点都遵循如下结构，就不难实现。
[头-左子树-尾] <-> 根结点 <-> [头-右子树-尾]
（定义DoublyList对象是为了便于理解，其实用数组就好了）
```java
class Solution {
    public Node treeToDoublyList(Node root) {
        if (root == null) return null;
        DoublyList doublyList = inorderHelper(root);
        doublyList.head.left = doublyList.tail;
        doublyList.tail.right = doublyList.head;
        return doublyList.head;
    }

    DoublyList inorderHelper(Node node) {
        if (node == null) return null;
        Node head, tail;

        DoublyList left = inorderHelper(node.left);
        if (left == null) {
            node.left = null;
            head = node;
        } else {
            left.tail.right = node;
            node.left = left.tail;
            head = left.head;
        }

        DoublyList right = inorderHelper(node.right);
        if (right == null) {
            node.right = null;
            tail = node;
        } else {
            node.right = right.head;
            right.head.left = node;
            tail = right.tail;
        }
        return new DoublyList(head, tail);
    }

    class DoublyList {
        Node head, tail;

        DoublyList(Node head, Node tail) {
            this.head = head;
            this.tail = tail;
        }
    }
}
```
