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

    private Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        while (root != null){
            stack.push(root);
            root = root.left;
        }
        this.stack = stack;
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode next = this.stack.pop();
        int res = next.val;
        
        //记得把右子树加入栈中
        next = next.right;
        while (next != null){
            this.stack.push(next);
            next = next.left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !this.stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
执行用时 :81 ms, 在所有 Java 提交中击败了92.52% 的用户
内存消耗 :49.8 MB, 在所有 Java 提交中击败了99.47%的用户
