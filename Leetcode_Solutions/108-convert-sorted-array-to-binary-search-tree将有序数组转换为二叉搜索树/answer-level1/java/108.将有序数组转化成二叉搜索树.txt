### 解题思路
1、根据二叉搜索树的特点，有序数组的中位数应该是二叉树的根节点
2、递归处理左右子树

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
        return convertToBST(nums,0,nums.length);
    }

    /**
     * 
     * @param nums 有序数组
     * @param start 递归的开始索引
     * @param end 递归结束索引的下一位
     * @return 根节点
     */
    private TreeNode convertToBST(int[] nums, int start, int end) {
        if(start == end){
            return null;
        }
        //避免超过int最大值
        int mid = (start + end) >>> 1;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = convertToBST(nums,start,mid);
        root.right = convertToBST(nums,mid+1,end);
        return root;
    }
}
```