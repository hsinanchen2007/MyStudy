### 解题思路
每次寻找数组的中间节点作为子树的根节点，最后返回的树一定满足题目条件。

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
        return makeSubTree(0, nums.length-1, nums);
    }

    public TreeNode makeSubTree(int left, int right,int[] nums){
        if (right < left) return null;
        //寻找新子树的根节点（若节点剩余个数为偶数个取右）
        int mid = (left + right) / 2 + (left + right) % 2;
        TreeNode root = new TreeNode(nums[mid]);
        if (right == left) return root;
        //递归寻找左右子树
        root.left = makeSubTree(left, mid-1, nums);
        root.right = makeSubTree(mid+1, right, nums);
        return root;
    }
}
```