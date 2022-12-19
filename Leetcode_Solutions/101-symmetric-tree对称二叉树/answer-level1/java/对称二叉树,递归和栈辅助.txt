### 解题思路

![image.png](https://pic.leetcode-cn.com/1d9b4deab5ec787cd82d916e5876f3f5d7b2af4e5037c202faf60faabe752ec1-image.png)

判断是否是对称二叉树,其实就是判断值是否相等,和左子树的左等于右子树的右,左子树右等于右子树的左

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

    //递归实现
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root,root);
    }
    private boolean isSymmetric(TreeNode leftNode,TreeNode rightNode){
        //如果左右都是空返回true
        if(leftNode==null&&rightNode==null){
            return true;
        }
        //如果只有一个是空返回false
        if(leftNode==null||rightNode==null){
            return false;
        }
        //判断值是否相等,和左子树的左等于右子树的右,左子树右等于右子树的左
        return (leftNode.val==rightNode.val)&&isSymmetric(leftNode.left,rightNode.right)&&isSymmetric(leftNode.right,rightNode.left);
    }
    //栈实现
    public boolean isSymmetric(TreeNode root) {
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode rightNode=stack.pop();
            TreeNode leftNode=stack.pop();
            //如果同时是空说明满足,跳出本次循环
            if(leftNode==null&&rightNode==null){
                continue;
            }
            if(leftNode==null||rightNode==null){
                return false;
            }
            //值不相等返回false
            if(leftNode.val!=rightNode.val){
                return false;
            }
            //右子树的右
            stack.push(rightNode.right);
            //左子树的左
            stack.push(leftNode.left);
            //左子树的右
            stack.push(leftNode.right);
            //右子树的左
            stack.push(rightNode.left);
        }
        return true;
    }
```