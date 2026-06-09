### 解题思路
中右左 -> 倒序 -> 左右中

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
    public List<Integer> postorderTraversal(TreeNode root) {
        //递归算法求后序遍历
        LinkedList<Integer> list = new LinkedList<>();

        if (root == null) {
            return list;
        }
        
        //后序遍历 前序遍历的 中左右 中右左->倒序 左右中 后序遍历
        Deque<TreeNode> stack = new LinkedList<>();

        //入队列
        stack.addFirst(root);
        
        //栈非空时
        while (!stack.isEmpty()) {
            
            //弹出栈
            TreeNode node = stack.removeFirst();
            list.addFirst(node.val);

            //左节点入栈
            if (node.left != null) {
                stack.addFirst(node.left);
            }

            //右节点入栈
            if (node.right != null) {
                stack.addFirst(node.right);
            }
        }


        //递归遍历
        //dfs(root, list);

        return list;
    }

    //递归后序遍历
    private void dfs(TreeNode root, List<Integer> list) {
        
        if (root == null) {
            return;
        }
        
        //左节点
        dfs(root.left, list);

        //右节点
        dfs(root.right, list);

        list.add(root.val);
    }
}
```