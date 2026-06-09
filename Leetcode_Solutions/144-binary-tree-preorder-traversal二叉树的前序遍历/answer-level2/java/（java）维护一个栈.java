### 解题思路
维护栈：按规则入栈 
 1. 和中序遍历不一样的是：中序被遍历后要从最深的那个左子结点开始存入数组
    遍历：根-根1-根1左-根1右 != 返回：根1左-根1-根1右-根
 2. 而前序遍历时遍历到哪个结点，就存入哪个结点
    遍历：根-根1-根1左-根1右 == 返回：

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;

        while (cur != null || !stack.isEmpty()) {
            while (cur != null) { // 当结点存在
                stack.push(cur); // 将此结点入栈
                res.add(cur.val); // 规则是被遍历就直接存入数组，和中序遍历不一样的是：中序被遍历后要从最深的那个左子结点开始存入数组
                cur = cur.left;
            }
            cur = stack.pop();
            cur = cur.right;
        }
        return res;
    }
}
```