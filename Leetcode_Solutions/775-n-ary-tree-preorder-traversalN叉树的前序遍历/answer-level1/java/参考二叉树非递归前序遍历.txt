### 解题思路
参考二叉树非递归前序遍历

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) {
            return list;
        }

        Stack<Node> stack = new Stack<>();
        stack.add(root);

        while (!stack.isEmpty()) {
            root = stack.pop();
            list.add(root.val);
            int len = root.children.size();
            for (int i = len - 1; i >= 0; i--) {
                Node node = root.children.get(i);
                if(node != null){
                    stack.add(node);
                }
            }
        }
        return list;
    }
}
```