
# 方法一：迭代

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
    public int sumOfLeftLeaves(TreeNode root) {
        if(root==null||root.left==null&&root.right==null) return 0;
        int sum=0;
        Stack<TreeNode> stack=new Stack<>();
        stack.push(root);
        while(!stack.empty()){
            TreeNode cur=stack.pop();
            TreeNode left=cur.left;
            TreeNode right=cur.right;
            //判断空
            if(left!=null){
                if(left.left!=null||left.right!=null){//左子树非叶子节点
                    stack.push(left);
                } else {//左子树为叶子节点
                    sum+=left.val;
                }  
            }
            if((right!=null)&&(right.left!=null||right.right!=null)){//右子树非叶子节点
                stack.push(right);
            }
        }
        return sum;
        
    }


}
```

方法二：递归
```java
public int sumOfLeftLeaves1(TreeNode root) {
        if(root==null) return 0;
        TreeNode left=root.left;
        TreeNode right=root.right;
        int l=0,r=0;
        if(left!=null){
            if(left.left!=null||left.right!=null){
                l=sumOfLeftLeaves1(left);
            } else {
                l=left.val;
            }
        }
        if((right!=null)&&(right.left!=null||right.right!=null)){
            r=sumOfLeftLeaves1(right);
        }
        return l+r;
    }
```
