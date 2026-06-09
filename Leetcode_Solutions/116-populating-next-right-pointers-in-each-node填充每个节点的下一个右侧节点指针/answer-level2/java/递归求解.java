## 递归求解
思路如下：
node.left.next = node.right;
node.right.next = node.next.left;

```java
class Solution {
    public Node connect(Node root) {
        if(root==null) return null;
        Node head = new Node();
        head.next = root;
        helper(root);
        return head.next;
    }
    public void helper(Node node){
        if(node.left == null) return;
        node.left.next = node.right;
        node.right.next = node.next == null ?null:node.next.left;
        helper(node.left);
        helper(node.right);
    }
}
```