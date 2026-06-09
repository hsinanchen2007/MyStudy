二叉搜索树满足：所有节点的左子树上的值小于该节点的值，右子树上的值大于该节点的值。
转换为累加树可以将树由大到小进行遍历（二叉树的中序遍历），记录累加值，逐步修改二叉树中节点的值。
以下是递归和非递归两种解法：

### 递归
```java
class Solution {
    int add = 0;
    public TreeNode convertBST(TreeNode root) {
        if(root == null){
            return null;
        }
        convertBST(root.right);
        root.val += add;
        add = root.val;
        convertBST(root.left);
        return root;
    }
}
```
### 非递归
使用栈来记录遍历过程中的节点值。以下是非递归算法的两种写法：
```java
class Solution {
    public TreeNode convertBST(TreeNode root) {
        if(root == null){
            return null;
        }
        int add = 0;
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode node = stack.peek();
            while(node != null){
                stack.push(node.right);
                node = node.right;
            }
            stack.pop();
            if(!stack.isEmpty()){
                node = stack.pop();
                node.val += add;
                add = node.val;
                stack.push(node.left);
            }
        }
        return root;
    }
}
```
使用p来记录遍历轨迹：
```java
class Solution {
    public TreeNode convertBST(TreeNode root) {
        if(root == null){
            return null;
        }
        int add = 0;
        TreeNode p = root;
        Stack<TreeNode> stack = new Stack();
        while(p != null || !stack.isEmpty()){
            if(p != null){
                stack.push(p);
                p = p.right;
            } else {
                p = stack.pop();
                p.val += add;
                add = p.val;
                p = p.left;
            }
        }
        return root;
    }
}
```
