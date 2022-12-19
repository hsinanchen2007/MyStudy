### 解题思路
根据题意给出的数组为有序数组，那么直接以数组的中点处元素为根节点。
1 小于根节点的元素为左子树节点
2 大于根节点的元素为右子树节点
3 同样递归建立其他节点。

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
           return helper(nums,0,nums.length-1); 
    }
    public TreeNode helper(int[] arr,int l,int r){
        if(l>r) return null;
        int mid=(l+r)/2;
        TreeNode root=new TreeNode(arr[mid]);
        root.left=helper(arr,l,mid-1);
        root.right=helper(arr,mid+1,r);
        return root;
    }
}
```