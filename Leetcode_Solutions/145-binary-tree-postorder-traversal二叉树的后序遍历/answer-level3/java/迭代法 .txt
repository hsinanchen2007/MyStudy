跟先序和中序遍历一样，用一个Stack存储还未遍历右子树的节点。  
用一个last记住上次遍历的节点，如果上次访问的点是右孩子，说明右子树已经遍历过了。

```Java []
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        TreeNode last = null;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.peek();
            if (node.right == null || node.right == last) {
                ans.add(node.val);
                stack.pop();
                last = node;
                node = null;
            } else {
                node = node.right;
            }
        }
        return ans;
    }
}
```


更为简洁的写法。这种解法的思想是先序遍历的变形，先序遍历是“根->左->右”，后序遍历是“左->右->根”，那么把先序遍历改成“根->右->左”，再逆序一下就是后序遍历。

```Java []
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new LinkedList<>();
        if (root == null) return ans;
        
        Stack <TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode node;
        while (!stack.isEmpty()) {
            node = stack.pop();
            ans.add(0, node.val);
            if (node.left != null) {
                stack.push(node.left);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
        }
        return ans;
    }
}
```