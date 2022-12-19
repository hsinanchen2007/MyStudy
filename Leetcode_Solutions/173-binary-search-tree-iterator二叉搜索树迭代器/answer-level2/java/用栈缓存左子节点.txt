执行结果：
通过
显示详情
执行用时 :
113 ms
, 在所有 Java 提交中击败了
90.44%
的用户
内存消耗 :
50.1 MB
, 在所有 Java 提交中击败了
99.20%
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
class BSTIterator {
    Stack<TreeNode> st = new Stack<TreeNode>();
    
    public BSTIterator(TreeNode root) {
        if(root==null)return;
        TreeNode cu = root;
        do{
            st.push(cu);
        }while((cu=cu.left)!=null);
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode tn = st.pop();
        if(tn.right==null){
            return tn.val;
        }else{
            TreeNode cu = tn.right;
            do{
                st.push(cu);
            }while((cu=cu.left)!=null);
            return tn.val;
        }
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !st.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```
