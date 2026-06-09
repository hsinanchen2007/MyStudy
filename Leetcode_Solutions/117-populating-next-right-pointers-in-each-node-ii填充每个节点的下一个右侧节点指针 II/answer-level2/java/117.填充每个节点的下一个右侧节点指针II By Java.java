### 解题思路
1. 使用数组模拟栈，按照层次数压入栈。
2. 如果当前层数>栈的长度，说明该节点第一次入栈，直接压入。
3. 如果当前层数<=栈的长度，将所在层数的节点从栈中取出，此节点的Next就是当前节点，将当前节点替换栈中当前层数的值。

空间复杂度为常量，既树的深度H。

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
    
  private void recur(Node root, ArrayList<Node> s, int hier) {
    if (root == null) {
      return;
    }
    if (s.size() < hier) {
      s.add(hier - 1, root);
    } else {
      Node prev = s.get(hier - 1);
      prev.next = root;
      s.set(hier - 1, root);
    }
    recur(root.left, s, hier + 1);
    recur(root.right, s, hier + 1);
  }

  public Node connect(Node root) {
    ArrayList<Node> s = new ArrayList();

    recur(root, s, 1);
    return root;
  }
}
```