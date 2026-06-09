### 解题思路
递归的思路。l与r分别记录当前数组的左右端索引。
1.findMax函数，找到目前数组的最大值索引。
2.maxTree函数，将找到目前数组的最大值索引，作为当前最大二叉树根节点。然后将剩下的数组分为两段，左边作为左子树，右边作为右子树，分别递归调用maxTree函数。
3.结束条件。当目前的数组左端索引大于右端，表示已经没有数了，则意味着这个节点为null.

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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return maxTree(nums,0,nums.length-1);
    }
    //find the index of the max number
    public int findMax(int[] nums,int l, int r){
        int max=0,maxIndex=l;
        for(int i=l;i<=r;i++){
            if(max<nums[i]){
                max=nums[i];
                maxIndex=i;
            }
        }
        return maxIndex;
    }
    //bond is the index of the current array
    public TreeNode maxTree(int[] nums,int l,int r){
        if(l>r){
            return null;
        }
        int bond=findMax(nums,l,r);
        TreeNode root=new TreeNode(nums[bond]);
        root.left=maxTree(nums,l,bond-1);
        root.right=maxTree(nums,bond+1,r);
        return root;
    }
}
```