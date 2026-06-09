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
class BSTIterator {
    List<Integer> l = new ArrayList<>();
    int i = 0;
    public BSTIterator(TreeNode root) {
        h(l, root);
    }

    private void h(List<Integer> l, TreeNode root) {
        if(root == null)
            return;
        h(l, root.left);
        l.add(root.val);
        h(l, root.right);
    }
    
    /** @return the next smallest number */
    public int next() {
        int rs = l.get(i);
        i ++;
        return rs;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return i != l.size();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
