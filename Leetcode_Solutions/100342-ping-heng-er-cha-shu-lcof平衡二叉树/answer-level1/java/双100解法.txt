![微信截图_20200402211345.png](https://pic.leetcode-cn.com/95d53d7933ed87eb48ba32b327f512c5052075bfc32efb80e282fb09d13f5bab-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200402211345.png)

```
    boolean tagTree = true;
    public boolean isBalanced(TreeNode root) {
        depthOfNode(root);
        return tagTree;
    }
    public int depthOfNode(TreeNode node){
        if (!tagTree)
            return 0;
        if (node==null)
            return 0;
        int leftDepth = depthOfNode(node.left);
        int rightDepth = depthOfNode(node.right);
        if (Math.abs(leftDepth-rightDepth)>1)
            tagTree = false;
        return Math.max(leftDepth,rightDepth)+1;
    }
```
