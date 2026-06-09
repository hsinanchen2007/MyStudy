### 1. 递归

这道题递归的时候只需要考虑两种情况，一种是偷取父节点所获得的最大的收益，一种是不偷取父节点所获得的最大的收益，那对应到代码上就是如果偷取父节点，那就只能偷取孙子节点，如果不偷取父节点，就可以偷取左孩子和右孩子节点，将这两种情况所获得的最大收益进行比较，返回一个较大者就好了。
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
    //这个递归函数的作用是求得以root为根的树所能获得的最大的收益
    public int rob(TreeNode root) {
        if(root==null) return 0;
    
        int one=root.val;
        if(root.left!=null) one+=rob(root.left.left)
                                +rob(root.left.right);
        if(root.right!=null) one+=rob(root.right.left)
                                +rob(root.right.right);
        int two=0;
        two=rob(root.left)+rob(root.right);
        
        return Math.max(one,two);
    }
}
```

### 2. 记忆化搜索
我们发现，递归函数中会对同一颗子树的最大的收益有多次的计算，所以这里可以使用记忆化搜索来解决，对于记忆化搜索，就是使用map来存储对应的根节点及它的最大收益，如果计算到了重复的根节点直接返回，使得时间复杂度降低为O(n)
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
    //这个递归函数的作用是求得以root为根的树所能获得的最大的收益
    Map<TreeNode,Integer> memo=new HashMap<>();
    public int rob(TreeNode root) {
        if(root==null) return 0;
        
        if(memo.containsKey(root)) return memo.get(root);
         
        int one=root.val;
        if(root.left!=null) one+=rob(root.left.left)
                                +rob(root.left.right);
        if(root.right!=null) one+=rob(root.right.left)
                                +rob(root.right.right);
        int two=0;
        two=rob(root.left)+rob(root.right);
        
        memo.put(root,Math.max(one,two));
        return Math.max(one,two);
    }
}
```
### 3.动态规划
这种方法是使用一个2大小的数组，记录每个节点偷或者不偷所对应的最大收益，其中下标0表示不偷取当前节点，下标1表示偷取当前节点，那状态转移方程就可以表示为
> root[0]=max(left[1],left[0])+max(right[0],right[1]);
> root[1]=left[0]+right[0]+root.val;

在这里root指的是根节点所对应的最大收益数组,left指的是根节点左孩子对应的最大收益数组，right指的是根节点右孩子对应的最大收益数组。

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
    public int rob(TreeNode root) {
        //设置一个数组保存以某个节点为根节点的树所能获得的最大的收益
        int[] num=maxValue(root);
        
        return Math.max(num[0],num[1]);
    }
    
    int[] maxValue(TreeNode root){
        if(root==null) return new int[2];
        
        int cur[]=new int[2];//保存根节点的最大的收益
        
        int left[]=maxValue(root.left);
        int right[]=maxValue(root.right);
        cur[0]=Math.max(left[0],left[1])+
            Math.max(right[0],right[1]);
        cur[1]=root.val+left[0]+right[0];
        
        return cur;
    }
}
```