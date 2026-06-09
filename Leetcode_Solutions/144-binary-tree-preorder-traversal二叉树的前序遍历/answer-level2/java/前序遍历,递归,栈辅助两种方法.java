### 解题思路

前序遍历:根左右
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
    //递归的形式
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result=new ArrayList<>();
        preorderTraversal(root,result);
        return result;
    }
    private void preorderTraversal(TreeNode root,List<Integer> result){
        if(root==null){
            return;
        }
        //根
        result.add(root.val);
        //左
        preorderTraversal(root.left,result);
        //右
        preorderTraversal(root.right,result);
    }
```
```java
    //使用栈辅助,注意左右子树的push的顺序,因为栈先进后出
    public List<Integer> preorderTraversal(TreeNode root){
        List<Integer> result=new ArrayList<>();
        if(root==null){
            return result;
        }
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode treeNode=stack.pop();
            //根
            result.add(treeNode.val);
            //先push右
            if(treeNode.right!=null){
                stack.push(treeNode.right);
            }
            //后push左
            if(treeNode.left!=null){
                stack.push(treeNode.left);
            }
        }
        return result;
    }

```