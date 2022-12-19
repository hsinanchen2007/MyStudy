### 解题思路
迭代解决中序遍历时，我们用到一个栈，
        每次将当前栈顶的左子节点加入栈，直到栈顶节点没有左子节点，这个操作作为一个函数，后面每加入一个出栈的节点的右子节点时，仍要如此操作，
然后回到这个问题，每出栈一次，则将上诉操作进行一次，且判断是否是第k小的节点，满足返回栈顶元素的节点即可；

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

class Solution {
    Stack<TreeNode> s;
    public int kthSmallest(TreeNode root, int k) {
        s = new Stack<>();
        if (root == null) {
            return 0;
        }
        addLeft(root);
        while (k>1) {
            TreeNode node = s.pop();
            if (node.right != null) {
                addLeft(node.right);
            }
            k--;
        }
        return s.peek().val;
    }
    public void addLeft(TreeNode node) {
        s.push(node);
        while (node.left != null) {
            node = node.left;
            s.push(node);
        }
    }
}
```