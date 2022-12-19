### 解题思路
此处撰写解题思路

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
        int length = nums.length;
        return subSortedArrayToBST(nums, 0, length - 1);
    }

    public TreeNode subSortedArrayToBST(int[] nums,  int startIndex, int endIndex) {
        if (startIndex == endIndex) {
            TreeNode curNode = new TreeNode(nums[startIndex]);
            return curNode;
        } else if (startIndex < endIndex){
            int curIndex = (int)(startIndex + endIndex) / 2;
            TreeNode curNode = new TreeNode(nums[curIndex]);
            TreeNode leftNode = subSortedArrayToBST(nums, startIndex, curIndex - 1);
            TreeNode RightNode = subSortedArrayToBST(nums, curIndex + 1, endIndex);
            curNode.left = leftNode;
            curNode.right = RightNode;

            return curNode;
        } else {
            return null;
        }
    }
}
```