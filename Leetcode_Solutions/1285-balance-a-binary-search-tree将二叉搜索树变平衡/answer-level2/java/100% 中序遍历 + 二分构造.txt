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
    public void mid(TreeNode root, ArrayList<TreeNode> que){
        if(root == null) return;
        mid(root.left,que);
        que.add(root);
        mid(root.right,que);
    }
    public TreeNode build(int left, int right, ArrayList<TreeNode> list){
        if(left == right){
            TreeNode node = list.get(left);
            node.left = null;
            node.right = null; 
            return node;
        }
        if(left > right) return null;
        int mid = (left+right)/2;
        TreeNode root = list.get(mid);
        root.left = build(left,mid-1,list);
        root.right = build(mid+1,right,list);
        return root;
    }
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<TreeNode> list = new ArrayList<>();
        mid(root,list);
        return build(0,list.size()-1,list);
    }
}
```
