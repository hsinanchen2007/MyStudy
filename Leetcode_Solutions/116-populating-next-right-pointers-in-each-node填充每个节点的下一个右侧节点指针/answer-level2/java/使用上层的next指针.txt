### 解题思路
如果不要求空间O(n)，则可以使用层序遍历
而本题可以使用基于上层的next指针的层级"遍历"

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
        //使用上层的next辅助下层填充
        if (root == null) {
            return null;
        }
        Node cur = root;

        while(cur.left != null) {
            Node tmp = cur;
            while(tmp != null) {
                tmp.left.next = tmp.right;
                if(tmp.next != null) {
                    tmp.right.next = tmp.next.left;
                }
                tmp = tmp.next;
            }
            cur = cur.left;
        }
        return root;
    }
}
```