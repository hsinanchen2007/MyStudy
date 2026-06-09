### 解题思路
和下面的题类似
[543.二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)
[563.二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/)
设置一个全局变量
只是543和563在每次递归时都需要更改这个全局变量的值
但是本题只有在满足条件下更改全局变量的值

### 代码

```java
//110.平衡二叉树
class Solution {
    boolean balance;

    public boolean isBalanced(TreeNode root) {  
        balance = true;     
        height(root);
        return balance;
    }

    public int height(TreeNode root){
        if(root == null)  return 0;
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        if( Math.abs(leftHeight-rightHeight) > 1)   balance = false;   //满足条件才可更改
        return Math.max(leftHeight, rightHeight) + 1;
    }

}
```

```java
//543.二叉树的直径
class Solution {
    public int result = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        helper(root);
        return result;
    }

    public int helper(TreeNode root){
        int leftHeight;
        int rightHeight;

        if(root != null){
            leftHeight = helper(root.left);
            rightHeight = helper(root.right);
            result = Math.max(leftHeight+rightHeight, result); 
            return Math.max(leftHeight, rightHeight)+1;
        }else{
            return 0;
        }   
    }

}
```

```java
//563.二叉树的坡度
class Solution {
    public int findTilt(TreeNode root) {
        int tilt = 0;
        //Integer tilt = new Integer(0);
        dfs(root, tilt);
        System.out.print("**" + tilt + " ");
        return tilt;
    }

    public int dfs(TreeNode root, int tilt){
        if(root != null){
            int left = dfs(root.left, tilt);
            int right = dfs(root.right, tilt);
            tilt += Math.abs(left-right);
            System.out.print(tilt + " ");
            return left+right+root.val;
        }else{
            return 0;
        }
    }
}
```
