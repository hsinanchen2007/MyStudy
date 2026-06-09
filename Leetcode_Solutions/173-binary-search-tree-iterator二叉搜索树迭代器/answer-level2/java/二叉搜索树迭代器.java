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
    //本题中需要用栈来辅助构造数据结构
    Stack<TreeNode> stack;  //辅助栈
    public BSTIterator(TreeNode root) {
        stack=new Stack<>();
        leftMostInorder(root);
    }
    
    public void leftMostInorder(TreeNode node)
    {
        while(node!=null)
        {
            stack.push(node);
            node=node.left;
        }
    }
    /** @return the next smallest number */
    public int next() {
        TreeNode node=stack.pop();
        leftMostInorder(node.right);
        return node.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return stack.size()>0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
```