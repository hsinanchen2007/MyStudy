```java
public class Solution {
    private class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x){val=x;}
    }
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1==null||t2==null)
            //如果两个节点有一个为null，只需要返回不为null的另一个节点即可
            
            return t1==null ? t2 : t1;
        
        t1.val = t1.val+t2.val;
        //节点的合并
        //递归
        t1.left = mergeTrees(t1.left, t2.left);
        t2.right = mergeTrees(t1.right, t2.right);
        return t1;
    }

}
```

