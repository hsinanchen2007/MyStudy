### 解题思路
二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。
那如何保证高度最小呢？当树中的任意结点的左右子树高度差都不超过 1 时，整棵树的深度最小。

下面是一种构造最小高度树的思路：

如果序列长度为 0，那么是一棵空树。
如果序列长度为 1，那么只有一个根节点。
如果长度大于 1，那么选取中间位置的数赋给根节点，然后前一半递归构建左子树，后一半递归构建右子树。

参考链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci/solution/tu-jie-di-gui-gou-zao-ping-heng-er-cha-sou-suo-shu/


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
    public TreeNode sortedArrayToBST(int[] nums) {
        /*
        考察两个知识点
        （1）二叉树的构建
        （2）二叉搜索树
        */
        return buildTree(nums);
     
        
    }
    public TreeNode buildTree(int[] nums){
        if(nums==null||nums.length<=0)
            return null;

        int len=nums.length;
        if(len==1){
            return new TreeNode(nums[0]);
        }
        int mid=len/2;
        TreeNode root=new TreeNode(nums[mid]);
        //二叉树构建时注意数组的范围
        root.left=buildTree(Arrays.copyOfRange(nums,0,mid));
        root.right=buildTree(Arrays.copyOfRange(nums,mid+1,len));
        return root;
    }
}
```