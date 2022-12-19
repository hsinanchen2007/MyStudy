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
    public List<List<Integer>> findLeaves(TreeNode r) {
        // 找规律，子树高度
        List<List<Integer>> rs = new ArrayList<>();
        h(rs, r);
        return rs;
    }

    private int h(List<List<Integer>> rs, TreeNode r) {
        if(r == null)
            return 0;
        int hl = h(rs, r.left);
        int hr = h(rs, r.right);
        int ht = Math.max(hl, hr);
        while(ht >= rs.size()) {
            rs.add(new ArrayList<>());
        }
        rs.get(ht).add(r.val);
        return ht + 1;
    }
}
```
