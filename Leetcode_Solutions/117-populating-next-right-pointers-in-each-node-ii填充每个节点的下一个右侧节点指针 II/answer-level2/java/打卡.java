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
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root == null) return null;
        Queue<Node> queue = new LinkedList<Node>();
        
        queue.add(root);
        int size = queue.size();

        while(size != 0) {
            
            while(--size != 0) {
                Node head = queue.poll();
                if(head.left != null) queue.add(head.left);
                if(head.right != null) queue.add(head.right);
                head.next = queue.peek();
            }
            
            Node head = queue.poll();
            if(head.left != null) queue.add(head.left);
            if(head.right != null) queue.add(head.right);
            head.next = null;
            
            size = queue.size();
        }
        return root;
    }
}
```