### 解题思路
1. 二叉树搜索树的特征决定了，左最小，中其次，右最大，采用中序遍历一遍存储到列表中，就可以直接利用列表的迭代特征实现迭代器。
2. 如果是一般的二叉树，则可进行一次排序来实现，代码中已经进行了注释。
### Java代码

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
    private TreeNode root;
    private TreeNode node;
    private List<Integer> cachedList;
    private Iterator<Integer> it;
    public BSTIterator(TreeNode root) {
        cachedList = new ArrayList<>();
        this.root = root;
        dfs(root);
       // Collections.sort(cachedList);
        this.it = cachedList.iterator();
    }
    private void dfs(TreeNode node) {
        if(Objects.isNull(node)) {
            return;
        }
        dfs(node.left);
        this.cachedList.add(node.val);
        dfs(node.right);
    }
    /** @return the next smallest number */
    public int next() {
        return this.it.next();
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        
        return this.it.hasNext();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```