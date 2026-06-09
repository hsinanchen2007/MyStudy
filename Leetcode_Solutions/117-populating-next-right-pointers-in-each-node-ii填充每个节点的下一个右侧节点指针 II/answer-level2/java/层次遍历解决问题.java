### 解题思路
通过层次遍历解决问题，每层如未到最后一个则连接起来

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
        if (root == null) {
            return null;
        }
        LinkedList<Node> list = new LinkedList<>();
        list.add(root);
        int levelSize = list.size();
        while (true) {
            for (int i=0;i<levelSize;i++) {
                Node node = list.removeFirst();
                if (i < levelSize-1) {
                    node.next = list.get(0);
                } else {
                    node.next = null;
                }
                if (node.left != null) {
                    list.add(node.left);
                }
                if (node.right != null) {
                    list.add(node.right);
                }
            }
            levelSize = list.size();
            if (levelSize == 0) {
                break;
            }
        }
        return root;
    }
}
```