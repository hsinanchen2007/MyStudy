### 解题思路
没搞懂题解一个个写的好难懂，不能说点能听懂的吗？
我很菜，我就是用队列接收中序遍历的结果，然后复用队列的poll 和 isEmpty方法。

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

    private Queue<Integer> mQueue = new LinkedList<>();
    
    public BSTIterator(TreeNode root) {
        init(root);
    }

    /** @return the next smallest number */
    public int next() {
        return mQueue.poll();
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !mQueue.isEmpty();
    }
    
    private void init(TreeNode root) {
        if (root == null) {
            return;
        }
        
        if (root.left != null) {
            init(root.left);
        }
        mQueue.add(root.val);
        if (root.right != null) {
            init(root.right);
        }
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```