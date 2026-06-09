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
    public int kthSmallest(TreeNode root, int k) {
        ArrayList<Integer> list = inorder(root, new ArrayList<Integer>(), 0, k);
        return list.get(k - 1);
    }
    public ArrayList<Integer> inorder(TreeNode root, ArrayList<Integer> list, int n, int k){
        if(root == null || n == k) return list;
        inorder(root.left,  list, n, k);
        list.add(root.val);
        n++;
        inorder(root.right, list, n, k);
        return list;
    }
}
```
