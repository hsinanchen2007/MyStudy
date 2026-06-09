[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_94_inorderTraversal.java)

```java
public class _94_inorderTraversal {

    public static void main(String[] args) {
        TreeNode treeNode = Util.generateTreeNode();
        Util.printTree(treeNode);
        _94_inorderTraversal inorderTraversal = new _94_inorderTraversal();
        //递归算法
        Util.printList(inorderTraversal.inorderTraversal(treeNode));
        Util.printList(inorderTraversal.inorderTraversal2(treeNode));

    }

    /**
     * 解题思路：
     * 按题目所说，递归算法{@link _94_inorderTraversal#inorderTraversal2(TreeNode)}很简单，我们试着迭代算法完成
     * 模拟递归，用一个栈保存遍历结果
     *
     * @param root
     * @return
     */
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            //左
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            //中
            result.add(curr.val);
            //右
            curr = curr.right;
        }
        return result;
    }

    /**
     * 递归算法
     *
     * @param root
     * @return
     */
    public List<Integer> inorderTraversal2(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        recursion(root, result);
        return result;
    }

    private void recursion(TreeNode root, List<Integer> result) {
        if (root == null) {
            return;
        }
        //左
        recursion(root.left, result);
        //中
        result.add(root.val);
        //右
        recursion(root.right, result);
    }
}

```