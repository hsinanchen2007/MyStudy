### 解题思路
感觉leetcode中的这类题目都是在考察相应语言的语言特点。比如java来说，就是在考察java类。

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
    private List<Integer> list;

    public void midorder(TreeNode node){
        if(node == null)
            return;
        midorder(node.left);
        list.add(node.val);
        midorder(node.right);
    }

    public BSTIterator(TreeNode root) {
        this.list = new ArrayList<>();
        midorder(root);
    }
    
    /** @return the next smallest number */
    public int next() {
        int res = -1;
        if(hasNext()){
            res = this.list.get(0);
            this.list.remove(0);
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(this.list.size() != 0)
            return true;
        else
            return false;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```