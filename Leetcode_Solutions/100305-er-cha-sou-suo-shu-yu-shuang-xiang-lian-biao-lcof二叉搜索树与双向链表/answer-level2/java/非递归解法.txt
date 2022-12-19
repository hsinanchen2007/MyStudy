### 解题思路
无非就是非递归中序遍历 改造一下。但是不知道为啥性能反而还没有递归优秀

### 代码

```java
class Solution {
    public Node treeToDoublyList(Node root) {
        Node head = new Node();
        if (root == null) {
            return null;
        }
        Stack<Node> stack = new Stack<>();
        Node curr = root;
        Node p = head;

        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            curr = stack.pop();
            p.right = curr;
            curr.left = p;
            p = curr;

            curr = curr.right;
        }
        p.right = head.right;
        head.right.left = p;
        return head.right;
    }
}
```