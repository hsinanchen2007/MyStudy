最近提交结果：
通过
显示详情 
执行用时 :
1 ms
, 在所有Java提交中击败了
98.07%
的用户
内存消耗 :
34.7 MB
, 在所有Java提交中击败了
39.65%
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
    
    public List<Integer> inorderTraversal(TreeNode root) {
        
        List<Integer> list = new ArrayList<Integer>();
        pro(root,list);
        return list;
    }
    
    public void pro(TreeNode node,List<Integer> list){
        if(node==null)return;
        if(node.left!=null){
            pro(node.left,list);
        }
        list.add(node.val);
        if(node.right!=null){
            pro(node.right,list);
        }
    }
}
```