### 解题思路
第一次ac的思路：通过先对树进行中序遍历，然后再根据遍历结果进行操作；
第二次ac的思路：想提升一部分性能，所以采用迭代思路，利用栈对树节点进行操作，
        初始化：访问根节点的左节点，一直访问下去，直到下一个点没有左节点，存到栈，
        next：访问栈顶元素，并出栈，按照初始化的思路，若当前节点右节点有左子节点，则存下去；
但是最后好像第二次的结果比第一次还慢，无语
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
    int index;
    Stack<TreeNode> s;
    public BSTIterator(TreeNode root) {
        s = new Stack<>();
        if (root == null) {
            return;
        }
        s.push(root);
        TreeNode n = s.peek();
        while (n.left != null) {
            s.push(n.left);
            n = s.peek();
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        TreeNode node = s.pop();
        if (node.right != null) {
            s.push(node.right);
            TreeNode n = s.peek();
            while (n.left != null) {
                s.push(n.left);
                n = s.peek();
            }
        }
        
        return node.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if (s.empty()) {
            return false;
        }
        return true;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```