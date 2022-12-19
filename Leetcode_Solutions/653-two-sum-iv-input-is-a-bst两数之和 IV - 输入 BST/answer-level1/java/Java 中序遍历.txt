用中序遍历得到按大小排列的数组，然后遍历数组，用双指针判断是否满足条件。

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
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer> nums = new ArrayList<Integer>();
        inOrder(root, nums);
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if(nums.get(i) + nums.get(j) == k)
                return true;
             if(nums.get(i) + nums.get(j) < k){
                 ++i;
             }else{
                 --j;
             }
        }
        return false;
    }
    
    public void inOrder(TreeNode root, ArrayList<Integer> nums) {
        if(root == null)
            return;
        inOrder(root.left, nums);
        nums.add(root.val);
        inOrder(root.right,nums);
    }
}
```
