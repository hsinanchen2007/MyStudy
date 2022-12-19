- 总体思路：用栈实现先序遍历。
- 核心：当将某节点的left节点加入栈时，顺带判断该left节点是否是叶子节点，如果是，则符合条件：sum += left.val。
    - 因为用栈做先序遍历一定会将每个节点都push到栈中，
    - 所以一定会找到所有的左儿子节点，在所有的左儿子节点中是叶子节点的所有节点。
```
public int sumOfLeftLeaves(TreeNode root) {
    if (root == null) return 0;
    Stack<TreeNode> stack = new Stack<>();
    TreeNode node = root;
    stack.push(node);

    int sum = 0;

    while (!stack.isEmpty()) {
        node = stack.pop();
        if (node.right != null) stack.push(node.right);
        if (node.left != null) {
            stack.push(node.left);
            // 核心逻辑
            if (node.left.left == null && node.left.right == null) {
                sum += node.left.val;
            } 
        } 
    }
    return sum;
}
```
