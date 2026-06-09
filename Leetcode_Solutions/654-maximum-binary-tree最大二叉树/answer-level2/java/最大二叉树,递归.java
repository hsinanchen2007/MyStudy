### 解题思路
每次扫描找出数组中的最大值作为一个节点，然后最大值左右两边的子数组分别递归构造此节点的左右节点。

代码属于草稿型，未优化。。。

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
        if(nums==null||nums.length<=0){
            return null;
        }
        TreeNode tmp=new TreeNode(0);
        buildTree(nums,0,nums.length-1,tmp,true);
        return tmp.left;
    }

    private void buildTree(int[] nums,int start,int end,TreeNode maxNode,boolean left){
        if(start==end){
            if(left){
                maxNode.left=new TreeNode(nums[start]);
            }else{
                maxNode.right=new TreeNode(nums[start]);
            }
            return;
        }
        int max=Integer.MIN_VALUE;
        int maxIndex=-1;
        for(int i=start;i<=end;i++){
            if(nums[i]>max){
                max=nums[i];
                maxIndex=i;
            }
        }
        if(left){
            maxNode.left=new TreeNode(nums[maxIndex]);
        }else{
            maxNode.right=new TreeNode(nums[maxIndex]);
        }
        if(maxIndex==start){
            buildTree(nums,start+1,end,left?maxNode.left:maxNode.right,false);
        }else if(maxIndex==end){
            buildTree(nums,start,end-1,left?maxNode.left:maxNode.right,true);
        }else{
            buildTree(nums,start,maxIndex-1,left?maxNode.left:maxNode.right,true);
            buildTree(nums,maxIndex+1,end,left?maxNode.left:maxNode.right,false);
        }
    }
}
```