详细说明：[https://yuanyu.blog.csdn.net/article/details/103560588](https://yuanyu.blog.csdn.net/article/details/103560588)
```java
/**
 * 144. 二叉树的前序遍历：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * 94. 二叉树的中序遍历：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 145. 二叉树的后序遍历：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 */
public class Solution {
    private static class Command {
        String s;   // go, print
        TreeNode node;
        Command(String s, TreeNode node) {
            this.s = s;
            this.node = node;
        }
    }
    //preorderTraversal
    //inorderTraversal
    //postorderTraversal
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Deque<Command> stack = new ArrayDeque<>();
        stack.push(new Command("go", root));
        while (!stack.isEmpty()) {
            Command command = stack.pop();
            if (command.s.equals("print")) {
                res.add(command.node.val);
            } else {//command.s.equals("go");
                //后序遍历 
                //stack.push(new Command("print", command.node));
                if (command.node.right != null) {
                    stack.push(new Command("go", command.node.right));
                }
                //中序遍历 
                //stack.push(new Command("print", command.node));
                if (command.node.left != null) {
                    stack.push(new Command("go", command.node.left));
                }
                //前序遍历 
                //stack.push(new Command("print", command.node));
            }
        }
        return res;
    }
}
```


