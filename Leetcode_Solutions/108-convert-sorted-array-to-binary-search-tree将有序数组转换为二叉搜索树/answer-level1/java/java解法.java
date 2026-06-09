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
         return tree(0,nums.length-1,nums);
    }
    public TreeNode tree(int left,int right,int[] nums){
        if(left>right){
          return null;  
        }//退出条件
        int p=(left+right)/2;//找出中点,奇数是正好那个位置,偶数则是中点左边的位置.[1,2,3,4,5]中点是3,[1,2,3,4,5,6]值为2.5,因为/的特性,所以值为2
        TreeNode root = new TreeNode(nums[p]);
        root.left=tree(left,p-1,nums);//必须是left,因为如果从0开始,在根节点右子树的左节点上根本遍历不到数据.
        root.right=tree(p+1,right,nums);
        return root;
    }
}
```