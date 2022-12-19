### 解题思路
中序遍历： 算出数组中间的索引。
创建TreeNode，递归求出左右节点。


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

    int[]nums;
    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
       return this.helper(0,nums.length -1);
    }

    public TreeNode helper(int left,int right){
        if(left > right){
            return null;
        }

        int p = (right + left) / 2;

        TreeNode node = new TreeNode(nums[p]);

        node.left = helper(left,p - 1);

        node.right = helper(p + 1,right);

        return node;
    }

}
```