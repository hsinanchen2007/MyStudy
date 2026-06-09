类似于利用[105、中序和前序遍历构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)，按照此方式进行递归。
```
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        if(nums == null || nums.length == 0){
            return null;
        }
        return constructTree(nums,0,nums.length - 1);
    }

    private TreeNode constructTree(int[] nums,int start,int end){
        if(start > end){
            return null;
        }
        int index = getMax(nums,start,end);
        TreeNode root = new TreeNode(nums[index]);
        root.left = constructTree(nums,start,index - 1);
        root.right = constructTree(nums,index + 1,end);
        return root;
    }

    private int getMax(int[] nums,int start,int end){
        int index = start;
        for(int i = start;i <= end;i++){
            if(nums[index] < nums[i]){
                index = i;
            }
        }
        return index;
    }
}
```
