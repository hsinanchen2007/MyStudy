感觉o(h)内存和next的o(1)有冲突，要o(1)的话就需要o(n)的内存，感到困惑

```
class BSTIterator {

    LinkedList<TreeNode> linkedList = new LinkedList<>();
    public BSTIterator(TreeNode root) {
        if(root==null)
            return ;
        linkedList.push(root);
        while(root.left!=null){
            linkedList.addFirst(root.left);
            root = root.left;
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode t = linkedList.pop();
        if(t.right!=null){
            TreeNode right = t.right;
            linkedList.addFirst(right);
            while(right.left!=null){
                linkedList.addFirst(right.left);
                right = right.left;
            }
        }
        return t.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !linkedList.isEmpty();
    }
}
```
