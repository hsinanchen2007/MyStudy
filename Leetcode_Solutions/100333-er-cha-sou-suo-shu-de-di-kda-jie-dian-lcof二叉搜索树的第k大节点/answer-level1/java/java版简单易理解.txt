### 解题思路
利用搜索二叉树的性质，中序遍历的结果为递增序列。把前序遍历的结果放在数组中。
第k大元素也即是倒数第k个元素=顺序的第list.size()-k个元素

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
    List<Integer> list=new ArrayList<Integer>();
    int res;
    public int kthLargest(TreeNode root, int k) {
       helper(root);
       int len=list.size();
       return list.get(len-k);
}
    public  void  helper(TreeNode root){
    if(root==null) return;
    helper(root.left);
    list.add(root.val);
    helper(root.right);
}
}
```