和题解中某位小伙伴一样，借助了"求二叉树深度"（题号104）那一题的思路，解法如下：
```java
class Solution {
    private boolean flag=true;
    public boolean isBalanced(TreeNode root) {
        getDepth(root);
        return flag;
    }

    private int getDepth(TreeNode node){
        if(node==null){
            return 0;
        }
        int leftDepth = getDepth(node.left);
        int rightDepth = getDepth(node.right);
        if(Math.abs(leftDepth-rightDepth)-1>0){
            flag = false;
        }
        return 1+Math.max(leftDepth,rightDepth);
    }
}
```

