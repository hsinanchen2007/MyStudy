### 解题思路
借助中序，先把二叉排序树的值用LinkedList 保存，然后就很简单了
![image.png](https://pic.leetcode-cn.com/17aa29d1ff26e509dc873e130717acf9a2aafdb3df5c74b2589dd69f1acd8a30-image.png)


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
    private LinkedList<Integer> list = new LinkedList<>();

    // in order
    public BSTIterator(TreeNode root) {
        inOrder(root);
    }

    private void inOrder(TreeNode root) {
        if (root != null) {
            if (root.left != null) {
                inOrder(root.left);
            }
            list.add(root.val);
            if (root.right != null) {
                inOrder(root.right);
            }
        }
    }

    /** @return the next smallest number */
    public int next() {
        return list.removeFirst();
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return list.size() > 0;
    }

}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```