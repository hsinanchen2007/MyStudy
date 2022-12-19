执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
66.89%
的用户
内存消耗 :
39.3 MB
, 在所有 Java 提交中击败了
54.35%
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
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        get(root,sum,0,new ArrayList<Integer>());
        return res;
    }
    private void get(TreeNode tn, int sum, int cur,List<Integer> list){
        if(tn==null)return ;
        cur = cur + tn.val;
        
        if(tn.left==null&&tn.right==null){
            if(cur==sum){
                List<Integer> ll = new ArrayList<Integer>(list);
                ll.add(tn.val);
                res.add(ll);
            }
            return;
        }
        list.add(tn.val);
        if(tn.left!=null){
            List<Integer> l1 = new ArrayList(list);
            get(tn.left,sum,cur,l1);
        }
        if(tn.right!=null){
            get(tn.right,sum,cur,list);
        }
         
    }
}
```
