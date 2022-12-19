### 解题思路
此方法和题199的解题思路一致。
使用列表记录该深度下最后一次出现的节点，如果再出现该深度的节点，便将此前最后一次出现的节点的next指针指向新节点，并更新列表即可。

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
        ArrayList<Node> rightest = new ArrayList<Node>();
        helper(rightest, root, 0);
        return root;
    }

    public void helper(ArrayList<Node> list, Node root, int currLevel) {
        if(root == null) {
            return;
        }
        if(list.size() == currLevel) {
            list.add(root);
            helper(list, root.left, currLevel + 1);
            helper(list, root.right, currLevel + 1);
            return;
        }
        list.get(currLevel).next = root;
        list.set(currLevel, root);
        helper(list, root.left, currLevel + 1);
        helper(list, root.right, currLevel + 1);
        return;
    }
}
```