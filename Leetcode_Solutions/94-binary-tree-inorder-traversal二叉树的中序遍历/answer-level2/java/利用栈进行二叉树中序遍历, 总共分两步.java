**递归方法**可以通过**栈或者队列**的数据结构转化为**迭代方式**

进行二叉树中序遍历的步骤为：
Step 1: 判断当前node是否为null
Step 1.1: 不为null则入栈
Step 1.2: 为null出栈，并将当前出栈node的val存入链表， 将当前node修改为node->right, 重复Step 1

```java []
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<TreeNode> stack = new ArrayList<>();
        List<Integer> result = new ArrayList<>();
        TreeNode tmp = root;
        
        while (tmp != null || !stack.isEmpty()) {
            if (tmp != null) {
                stack.add(tmp);
                tmp = tmp.left;
                continue;
            }
            //出栈
            if (!stack.isEmpty()) {
                tmp = stack.remove(stack.size() - 1);
                result.add(tmp.val);
                tmp = tmp.right;
            }
        }
        
        return result;
    }
}
```
