### 解题思路
单调栈的方法题解如下，只是为啥效率还不如递归？

### 代码

```java

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        Stack<TreeNode> monoStack = new Stack<>();
        for (int num : nums) {
            TreeNode treeNode = new TreeNode(num);
            TreeNode pre = null;
            while (!monoStack.isEmpty() && monoStack.peek().val < num) {
                monoStack.peek().right = pre;
                pre = monoStack.pop();
            }
            treeNode.left = pre;
            monoStack.push(treeNode);
        }
        TreeNode pre = null;
        while (!monoStack.isEmpty()) {
            monoStack.peek().right = pre;
            pre = monoStack.pop();
        }
        return pre;
    }
}
```