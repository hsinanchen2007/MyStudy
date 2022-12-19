### 解题思路
> 二叉搜索树的中序遍历是一个递增序列

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
        private Deque<Integer> deque;

        public BSTIterator(TreeNode root) {
            deque = new LinkedList<>();
            inOrder(root);
        }

        /**
         * @return the next smallest number
         */
        public int next() {
            return deque.removeFirst();
        }

        /**
         * @return whether we have a next smallest number
         */
        public boolean hasNext() {
            return !deque.isEmpty();
        }
        
        private void inOrder(TreeNode root) {
            if (root == null) return;
            inOrder(root.left);
            deque.add(root.val);
            inOrder(root.right);
        }

    }

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```