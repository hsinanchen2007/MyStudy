![图片.png](https://pic.leetcode-cn.com/626c850ca9f0829a47ba4c33bf1b6d4a3c06f75abf0073d03f7b1c8f0ae83feb-%E5%9B%BE%E7%89%87.png)
```
class Solution {
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        if(Math.abs(hight(root.left)-hight(root.right))>1) return false;
        return isBalanced(root.right)&&isBalanced(root.left);
       
    }
    public int hight(TreeNode root){
        if(root==null) return 0;
        int right = hight(root.right)+1;
        int left = hight(root.left)+1;
        return right>left?right:left;

    }
}
```
