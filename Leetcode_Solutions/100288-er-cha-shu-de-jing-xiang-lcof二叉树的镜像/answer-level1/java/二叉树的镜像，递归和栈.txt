### 解题思路
![image.png](https://pic.leetcode-cn.com/2228cec0be05b501ccf31dc6fe7262dada66920dc0669f3886084dc9b65aaec8-image.png)

其实就是左字树与右子树互换

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
class Solution {
    //递归形式
    public TreeNode mirrorTree(TreeNode root) {
        if(root==null){
            return root;
        }
        //先将左子树保存
        TreeNode temp=root.left;
        //将右子树赋给左子树
        root.left=mirrorTree(root.right);
        //将左子树赋给右子树,至于使用临时变量temp,是因为左子树已经被修改了,所以需要使用临时变量
        root.right=mirrorTree(temp);
        return root;
    }
}
```java
class Solution {
    //辅助栈的形式
    public TreeNode mirrorTree(TreeNode root){
        if(root==null){
            return root;
        }
        Stack<TreeNode> stack=new Stack<>();
        //将节点推入栈中
        stack.push(root);
        //当栈为空的时候退出
        while(!stack.isEmpty()){
            TreeNode node=stack.pop();
            //左子树赋值到临时变量
            TreeNode temp=node.left;
            //左子树等于右子树
            node.left=node.right;
            //右子树等于左子树
            node.right=temp;
            //左右子树不为空时,推人栈中
            if(node.left!=null){
                stack.push(node.left);
            }
            if(node.right!=null){
                stack.push(node.right);
            } 
        }
        return root;
    }
}
```