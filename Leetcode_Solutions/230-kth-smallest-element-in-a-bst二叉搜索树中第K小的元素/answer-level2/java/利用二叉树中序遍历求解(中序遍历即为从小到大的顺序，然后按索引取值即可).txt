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
    public int kthSmallest(TreeNode root, int k) {
        //中序遍历即可求解(从小到大)
        List<Integer>list = new ArrayList<>();
        helper(root,list);
        return list.get(k-1);
    }
    public void helper(TreeNode root,List<Integer>list){
        if(root==null) return;
        if(root.left!=null) helper(root.left,list);
        list.add(root.val);
        if(root.right!=null) helper(root.right,list);
    }
}
```