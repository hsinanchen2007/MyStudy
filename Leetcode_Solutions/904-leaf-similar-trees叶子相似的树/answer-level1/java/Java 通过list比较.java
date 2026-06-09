执行用时 :1 ms , 在所有 Java 提交中击败了 99.41% 的用户
内存消耗 : 34.1 MB , 在所有 Java 提交中击败了96.33%的用户
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
    private List<Integer> list1 = new ArrayList<>();
    private List<Integer> list2 = new ArrayList<>();
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        helper(root1,list1);
        helper(root2,list2);
        
        if(list1.size()!=list2.size()) return false;
        for(int i = 0;i<list1.size();i++){
            if(list1.get(i)!= list2.get(i)){
                return false;
            }
        }
        
        return true;

        
    }
    void helper(TreeNode root,List<Integer> list){
        if(root ==null) return;
        if(root.left == null && root.right==null){
            list.add(root.val);
        }
        helper(root.left,list);
        helper(root.right,list);
    }
}
```