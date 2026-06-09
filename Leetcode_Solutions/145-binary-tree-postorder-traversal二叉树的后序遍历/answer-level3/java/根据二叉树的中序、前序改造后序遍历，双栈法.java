首先给出中序遍历代码：
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            result.add(curr.val);
            curr = curr.right;
        }
        return result;
    }
}
```
在此基础上，改造代码结构，判断**只有从右孩子返回的节点，才能将该节点的值计入result**，我的改造方法比较麻烦，使用双栈法，**从左孩子返回的节点，不弹出栈，采用peek，从而继续遍历右子树，同时也不要忘记，把这个节点压入stack2**。
**每次当stack.peek()得到的节点，和stack2.peek()相同时，说明这是一个右子树遍历完成后的情况，进入循环，把根子节点计入result，并更新curr和两个栈，直到stack为空，此时curr无法再更新，说明root已经计入result，结束代码。**
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.peek();
            while (!stack2.isEmpty() && curr != null && curr.equals(stack2.peek())) {
                result.add(stack2.pop().val);
                stack.pop();
                if (stack.isEmpty()) {
                    return result;
                }
                curr = stack.peek();
            }
            stack2.push(curr);
            curr = curr.right;
        }
        return result;
    }
}
```
