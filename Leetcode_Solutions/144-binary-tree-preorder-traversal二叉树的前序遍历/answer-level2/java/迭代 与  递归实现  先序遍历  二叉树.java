# 二叉树 先序遍历 基本思想 :
- 先访问根节点，再访问 左子树 ， 最后 访问 右子树 
- 循环以上步骤 
- 左子树 为null时，访问 右节点
- 右子树为 null时，返回上一层

__递归遍历:__
```
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null) return new ArrayList<Integer>();
        
        List<Integer> list = new ArrayList<Integer>();
        preorderTraversal(root, list);
        return list;
    }
    
    public List<Integer> preorderTraversal(TreeNode root, List<Integer> list) {
        
        list.add(root.val);
        if(root.left != null)
            preorderTraversal(root.left, list);
        if(root.right != null)
            preorderTraversal(root.right, list);
        
        return list;
    }
    
}
```
__迭代遍历:__
```
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null) return new ArrayList<Integer>();
        Stack<TreeNode> nodeStack = new Stack<TreeNode>();
        nodeStack.push(root);
        List<Integer> list = new ArrayList<Integer>();
        
        while(nodeStack.size() != 0 ){
            TreeNode node = nodeStack.pop();
            list.add(node.val);            
            if(node.right != null)
                nodeStack.push(node.right);
            if(node.left != null)
                nodeStack.push(node.left);
        }
        
        return list;
        
    }
}
```