```
class BSTIterator {

    Iterator<Integer> iterator = null;
    public BSTIterator(TreeNode root) {
        List<Integer> list = new ArrayList();
        minNode(root, list);
        this.iterator = list.iterator();
    }
    
    public void minNode(TreeNode root, List<Integer> list){
        if(root == null) return;
        minNode(root.left, list);
        list.add(root.val);
        minNode(root.right, list);
        
    }
    
    /** @return the next smallest number */
    public int next() {
        return iterator.next();
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return iterator.hasNext();
    }
}
```
