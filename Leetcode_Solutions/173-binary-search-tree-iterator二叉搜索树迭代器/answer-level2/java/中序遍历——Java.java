思路：中序遍历后便得到一个升序序列。
<br/><br/>
```zephir
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
    
    List<Integer> list = new ArrayList<>();
    int index = 0;
    
    public BSTIterator(TreeNode root) {
        dfs(root);
    }
    
    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }
        
        dfs(root.left);
        list.add(root.val);
        dfs(root.right);
    }
    
    /** @return the next smallest number */
    public int next() {
        if (!hasNext()) {
            return Integer.MIN_VALUE;
        }
        return list.get(index++);
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return index < list.size();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
