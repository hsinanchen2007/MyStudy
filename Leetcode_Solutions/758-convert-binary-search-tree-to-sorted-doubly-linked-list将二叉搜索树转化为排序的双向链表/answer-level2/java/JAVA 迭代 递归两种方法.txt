
迭代和递归两种方法都是在中序遍历的基础上，
用一个first指针指向表头，
一个pre指针指向上一个节点（遍历完之后pre指针即指向表尾）。

递归方法是比较容易写的，
但是好像很多面试里喜欢要求写非递归的，所以写了个迭代版的。

迭代版本
```
class Solution {
        Node first;
        Node pre;
    public Node treeToDoublyList(Node root) {
        if (root == null) return null;
        Stack<Node> stack = new Stack<>();
        do {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            if (!stack.isEmpty()) {
                Node node = stack.pop();
                //first若为空则赋值，first只赋值一次
                if (first == null) {
                    first = node;
                }
                //pre为空则赋值
                if (pre == null) {
                    pre = node;
                }
                //否则将当前节点与pre连接，同时移动pre
                else {
                    pre.right = node;
                    node.left = pre;
                    pre = node;
                }
                root = node.right;
            }
        } while (!stack.isEmpty() || root != null);
        //连接头尾
        first.left = pre;
        pre.right = first;
        return first;
    }
}
```
递归版本
```
class Solution {
        Node first;
        Node pre;
    public Node treeToDoublyList(Node root) {
        if (root == null) return null;
        helper(root);
        first.left = pre;
        pre.right = first;
        return first;
    }
    public void helper(Node node) {
        if (node == null) return;

        //中序遍历先访问左子树
        helper(node.left);

        //访问当前节点
        //first若为空则赋值，first只赋值一次
        if (first == null) {
            first = node;
        }
        //pre为空则赋值
        if (pre == null) {
            pre = node;
        }
        //否则将当前节点与pre连接，同时移动pre
        else {
            pre.right = node;
            node.left = pre;
            pre = node;
        }

        //最后访问右子树
        helper(node.right);
    }
}
```

