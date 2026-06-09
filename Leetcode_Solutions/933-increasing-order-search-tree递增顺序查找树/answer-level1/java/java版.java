### 解题思路
采用中序遍历得到的结果存在数组中，此时数组为递增数组。然后按照题目要求连接节点即可。
注意连接的时候是重新建一棵二叉树，把相应的值赋给节点即可。
注意连接头节点的时候要用到辅助节点。

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
    public TreeNode increasingBST(TreeNode root) {
        if(root==null) return null;
        List<Integer> list=new ArrayList<Integer>();
        TreeNode node=new TreeNode(0);
        TreeNode cur=node;
        helper(root,list);
        for(int num:list){
            cur.right=new TreeNode(num);
            cur=cur.right;
        }
        return node.right;
    }
    public void helper(TreeNode root,List<Integer> list){
        if(root==null) return;
        helper(root.left,list);
        list.add(root.val);
        helper(root.right,list);
    }

}
```