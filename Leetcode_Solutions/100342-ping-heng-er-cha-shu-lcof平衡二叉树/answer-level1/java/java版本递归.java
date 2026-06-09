庆祝 LeetCode 和　剑指offer 合作！ 是真的开心！
```java
class Solution {
    public boolean isBalanced(TreeNode root) {
        //递归三部曲，二叉树的题目大部分都可以使用递归
        //1.找终止条件，树为空的时候即无需继续递归
        return depth(root) != -1;
        //2.找返回值，返回的应该是自己是否是BST以及左右子树的差值
        //3.一次递归应该做什么，左右子树的BST都是true，且要判断最后一次是否是BST
    }

    public static int depth(TreeNode root){
        if(root == null) return 0;
        int left = depth(root.left);
        if(left == -1) return -1;
        int right = depth(root.right);
        if(right == -1) return -1;
        return Math.abs(left - right) < 2 ? Math.max(left,right) + 1 : -1;
    }
}
```