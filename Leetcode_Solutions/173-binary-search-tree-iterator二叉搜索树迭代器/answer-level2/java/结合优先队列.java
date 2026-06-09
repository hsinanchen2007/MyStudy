```
class BSTIterator {
    Queue<Integer>ls = new PriorityQueue<Integer>();

    public BSTIterator(TreeNode root) {
        dfs(root);
    }
    public void dfs(TreeNode root) {
        if(root==null) {return ;}
        ls.add(root.val);
        if(root.left!=null)dfs(root.left);
        if(root.right!=null)dfs(root.right);
    }
    /** @return the next smallest number */
    public int next() {
        return ls.poll();
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(ls.size() == 0)
            return false;
        else return true;
    }
}
```
通过递归把所有结点存储到里面
通过一个优先队列进行存储数据 然后每一次读数据都是输出第一个结点

