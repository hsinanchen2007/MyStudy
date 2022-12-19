### 解题思路
最近看了左神的《程序员代码面试指南》，里面有个树形dp套路，在这可以套用一下，还是理解不够深刻，画了两三个小时才写出来

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
     class ReturnType{
        public int maxLeft;
        public int maxRight;
        public ReturnType(int maxLeft, int maxRight){
            this.maxLeft = maxLeft;
            this.maxRight = maxRight;
        }
    }
    private  int maxSum = Integer.MIN_VALUE;
    private static int maxRoot = Integer.MIN_VALUE;
    public  int maxPathSum(TreeNode root){
        if(root == null)
            return 0;
        maxPath(root);
        if(maxRoot < 0)
            return maxRoot;
        return maxSum;
    }
 public ReturnType maxPath(TreeNode root){
        if(root == null)
            return new ReturnType(0, 0);
        maxRoot = Math.max(root.val, maxRoot);
        ReturnType l = maxPath(root.left);
        ReturnType r = maxPath(root.right);
        int maxLeft = Math.max(root.val, root.val + Math.max(l.maxLeft, l.maxRight));
        int maxRight = Math.max(root.val, root.val + Math.max(r.maxLeft, r.maxRight));
        int[] maxSumArr = new int[]{root.val, maxLeft, maxRight, Math.max(l.maxLeft, l.maxRight)+Math.max(r.maxLeft, r.maxRight)+root.val};
        for(int item:maxSumArr)
            maxSum = Math.max(item, maxSum);
        return new ReturnType(maxLeft, maxRight);
    }
}
```