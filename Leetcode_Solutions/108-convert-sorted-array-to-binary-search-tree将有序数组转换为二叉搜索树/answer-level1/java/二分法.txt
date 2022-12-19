执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.53%
的用户
内存消耗 :
37.3 MB
, 在所有 Java 提交中击败了
96.33%
的用户
```
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
        int len = nums.length;
        if(len==0)return null;
        return get(nums,0,len-1);
    }
    private TreeNode get(int[] nums, int s, int e){
        if(e==s)return new TreeNode(nums[s]);
        int m = (s+e)>>1;
        TreeNode root = new TreeNode(nums[m]);
        if(m-1>=s)root.left=get(nums,s,m-1);
        if(m+1<=e)root.right=get(nums,m+1,e);
        return root;
    }
}
```
