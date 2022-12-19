### 复杂度分析
时间复杂度：O(k)
空间复杂度：O(1)
其中 k 为题目要求的第 k 大

### 解题思路
经过分析，发现在二叉搜索树中查找第 k 大节点的问题，
可以转换为对二叉搜索树进行逆中序遍历，即右-根-左的顺序遍历。
详细实现使用非递归的方法，因为递归算法不好保存当前处于第几大节点这个信息，返回时也不够友好
（不过这个问题应该可以用类变量来解决，没有细想了）
思路在注释里

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
    /**
     * 实际上就是右-根-左遍历
     */
    public int kthLargest(TreeNode root, int k) {
        // 当前遍历到第几大元素了
        int top = 0;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode node = root;

        while (!stack.isEmpty()) {
            while (node.right != null) {
                stack.push(node.right);
                node = node.right;
            }
            while (true) {
                // 没有右子节点了，则弹出栈顶即现有最大值
                TreeNode pop = stack.pop();
                // 相当于遍历了一个节点
                top++;
                if (top == k) {
                    return pop.val;
                }
                // 每弹出一个节点，就检查其是否有左子节点
                // 有就入栈
                if (pop.left != null) {
                    stack.push(pop.left);
                    node = pop.left;
                    // 有新节点入栈，重新判断是否有右子节点
                    break;
                }
                // 如果没有左子节点，则继续循环弹出栈操作
            }
        }
        return -1;
    }
}
```