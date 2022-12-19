（1）首先是思路，看到平衡二叉树——左右子树的的高度差不超过1，想到从数组的中间数值作为头结点来思考。
（2）具体递归中不要考虑太多，抓住当前结点与其左右两个子结点。
（3）本道题受到105题的启发，从数组下标着手进行递归。
```java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        int len = nums.length-1;
        return sortedArrayToBST(nums, 0, len);
    }

    TreeNode sortedArrayToBST(int[] nums, int start, int end){
        if(start > end){
            return null;
        }

        int index = (start+end)/2;
        TreeNode root = new TreeNode(nums[index]);
        root.left = sortedArrayToBST(nums, start, index-1);
        root.right = sortedArrayToBST(nums, index+1, end);

        return root;
    }
}
```