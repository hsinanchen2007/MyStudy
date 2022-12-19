### 解题思路
此处撰写解题思路

### 代码

```java
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
    List<TreeNode> list;
    int i=0;
    public BSTIterator(TreeNode root) {
        list=new ArrayList<>();
        this.help(root);
    }
    public void help(TreeNode root){
        if(root==null) return;
        help(root.left);
        list.add(root);
        help(root.right);
    }
    
    /** @return the next smallest number */
    public int next() {
        return list.get(i++).val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return i<=list.size()-1?true:false;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```