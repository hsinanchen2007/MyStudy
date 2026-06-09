执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
30.29%
的用户
内存消耗 :
37.4 MB
, 在所有 Java 提交中击败了
28.74%
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root==null)return res;
        List<TreeNode> st1 = new ArrayList<TreeNode>();
        st1.add(root);
        List<Integer> list = new ArrayList<Integer>();
        list.add(root.val);
        res.add(list);
        while(!st1.isEmpty()){
            List<TreeNode> ss = new ArrayList<TreeNode>(st1.size()<<1);
            List<Integer> ll = new ArrayList<Integer>(st1.size()<<1);
            for(TreeNode tn : st1){
                if(tn.left!=null){
                    ss.add(tn.left);
                    ll.add(tn.left.val);
                }
                if(tn.right!=null){
                    ss.add(tn.right);
                    ll.add(tn.right.val);
                }
            }
            st1 = ss;
            if(!ss.isEmpty())res.add(0,ll);
        }
        return res;
        
    }
}
```
