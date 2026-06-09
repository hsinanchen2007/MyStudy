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
        TreeNode n;
        n = find(nums, 0, nums.length-1);
        return n;
    }
    //利用二分查找找最大
    public int findMAX(int[] num, int low, int high) {
        if(high == low) {
            return low;
        } else {
            int mid = (low+high)/2;
            int max1 = findMAX(num,low,mid);
            int max2 = findMAX(num,mid+1,high);
            int max;
            if(num[max1] >= num[max2]) {
                max = max1;
            } else {
                max = max2;
            }
            return max;
        }
    }
    //利用递归对左子树、右子树和跟进行划分
    public TreeNode find(int[] num, int low, int high) {
        if (high < low || low > high) {
            return null;
        }
        if (low == high) {
            return new TreeNode(num[low]);
        } else {
            int max = findMAX(num, low, high);
            TreeNode n = new TreeNode(num[max]);
            n.left = find(num, low, max - 1);
            n.right = find(num, max + 1, high);
            return n;
        }
    }
}