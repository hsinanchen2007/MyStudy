### 解题思路
栈的特点-后进先出
因此二叉数的入栈顺序 应该是这样的
先进跟节点 出栈 - 然后进右节点 左节点 (后进先出特性)

### 代码

```java
import java.util.Deque;
import java.util.ArrayDeque;
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
        List<Integer> list = new ArrayList<>();

        //递归遍历
        //dfs(root, list);
        //循环写法 使用栈

        Deque<TreeNode> stack = new ArrayDeque<>();

        //特殊情况
        if (root == null) {
            return list;
        }

        //根节点入列表
        stack.addFirst(root);

        //队列不为空时
        while (!stack.isEmpty()) {
            
            TreeNode pre = stack.removeFirst();
            
            list.add(pre.val);

            //右节点入栈 充分利用栈的后进先出特性
            if (pre.right != null) {
                stack.addFirst(pre.right);
            }

            //左节点入栈
            if (pre.left != null) {
                stack.addFirst(pre.left);
            }
        }

        return list;
    }

    //递归写法
    private void dfs(TreeNode root, List<Integer> list) {
        
        if (root == null) {
            return;
        }

        list.add(root.val);

        //递归遍历左节点
        dfs(root.left, list);

        //递归遍历右节点
        dfs(root.right, list);
    }
}
```