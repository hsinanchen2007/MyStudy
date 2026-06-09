### 解题思路
递归扫描整颗二叉搜索树，对于每个节点，将其左子树的右边界连接到当前节点，当前节点再连接到右子树的左边界；返回左子树的左边界和右子树的右边界即可；（如果存在左子树和右子树）

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
        if (root == null) return null;
        var result = TreeToDoublyListCore(root);
        result[0].left = result[1];
        result[1].right = result[0];
        return result[0];
    }

    public static Node[] TreeToDoublyListCore(Node root)
    {
        Node left = root, right = root;
        if (root.left != null)
        {
            var leftList = TreeToDoublyListCore(root.left);
            left = leftList[0];
            leftList[1].right = root;
            root.left = leftList[1];
        }
        if (root.right != null)
        {
            var rightList = TreeToDoublyListCore(root.right);
            root.right = rightList[0];
            rightList[0].left = root;
            right = rightList[1];
        }

        return new Node[] { left, right };
    }
}
```