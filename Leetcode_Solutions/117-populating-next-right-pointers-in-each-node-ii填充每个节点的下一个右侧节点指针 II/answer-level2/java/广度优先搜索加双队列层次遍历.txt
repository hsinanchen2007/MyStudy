### 解题思路
1 广度优先来实现层级遍历
2 双队列来解决每一层的结尾来区分不同层级，避免当前层最后一个节点的next指向下一层的第一个节点。

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

        if(root == null) {
            return root;
        }
        
        Queue<Node> queue1 = new LinkedList();
        Queue<Node> queue2 = new LinkedList();

        queue1.offer(root);
        while(!queue1.isEmpty() || !queue2.isEmpty()) {
            while(!queue1.isEmpty()) {
                Node n = queue1.poll();
                n.next = queue1.peek();

                if(n.left!=null) {
                    queue2.offer(n.left);
                }
                if(n.right!=null) {
                    queue2.offer(n.right);
                }
            }

            while(!queue2.isEmpty()) {
                Node n = queue2.poll();
                n.next = queue2.peek();

                if(n.left!=null) {
                    queue1.offer(n.left);
                }
                if(n.right!=null) {
                    queue1.offer(n.right);
                }
            }
        }
        
        return root;
    }
}
```