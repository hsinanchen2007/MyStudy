执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.59%
的用户
内存消耗 :
35.3 MB
, 在所有 Java 提交中击败了
40.72%
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
    List<Integer> list = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root==null)return list;
        get(root);
        return list;
    }
    private void get(TreeNode tn){
        list.add(tn.val);
        if(tn.left!=null)get(tn.left);
        
        if(tn.right!=null)get(tn.right);
    }
}
```
