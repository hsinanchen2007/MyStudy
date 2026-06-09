这道题的题意是求出所给的二叉树中的最大的路径和，那很直接的一个思想就是找到过每个节点的最大的路径和，找到一个最大者不就好了吗？这里我们定义一个递归的函数，它的功能是求出过某个节点的单边的最长路径和，这里的单边指的就是最大路径和的路径只在这个节点的一边而不是两边，类似下面这张图
![image.png](https://pic.leetcode-cn.com/a1faa24e51dd91a9cf38742e40a930c38c8bfe0b26ba058a171ca0d69d02930a-image.png)
**这里过节点1的那个蓝色的路线就是两边，而过节点2的那条红色的路线就是单边**
那么我们就可以宏观的来想，既然这个函数是求过某个节点的单边的最大路径和，那么我们就用这个函数求出它左子树的单边的最大路径和`n`和右子树的单边的最大路径和`m`，然后与这个节点的值相加时要做一个判断，因为不管当前的这个节点的值是正是负，都不希望`n`或者`m`为负，这样的话只会让结果更小，所以在这里如果`n`或者`m`为负值，那么过这个节点的最大路径和中就不能包含它们，这时我们不就求出来过这个节点的最大路径和了吗？当然函数返回的还是过这个节点的单边的最大路径和，这个问题就很清晰的解决了！！
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
    int res=Integer.MIN_VALUE;
    
    //这个函数的作用是找到过root的单边的最长的路径
    int dfs(TreeNode root){
        //基线条件
        if(root==null) return 0;
        
        //求出左子树的最大的路径和
        int left=dfs(root.left);
        //求出右子树的最大路径和
        int right=dfs(root.right);
        
        //这里进行选择，如果左右子树的最大路径和是大于0的才与其相加
        int num=root.val;
        if(left>0) num+=left;
        if(right>0) num+=right;
        res=Math.max(res,num);//进行比较，将一个较大值赋给res
        
        return Math.max(root.val,Math.max(root.val+left,root.val+right));
    }
    
    public int maxPathSum(TreeNode root) {
    //经过某个节点的最大的路径和为左子树的最大路径和右子树的最大路径和加这个节点的值
        dfs(root);
        
        return res;
    }
}
```