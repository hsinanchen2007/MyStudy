### 解题思路
递归办法是内部有一个递归栈，迭代版模拟递归操作

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
        List<Integer> reslut = new ArrayList<>();
        if (root == null) {
            return reslut;
        }
        TreeNode p = root;
        TreeNode pVisit = null;
        Stack<TreeNode> stk = new Stack<>();
        stk.add(p);

        while (!stk.isEmpty()) {
            //只要你有左孩子，就将左孩子压入栈中
            if (p != null && p.left != null) {
                stk.add(p.left);
                p = p.left;
            } else {
                //栈顶元素，先出栈，可能还有右孩子
                p = stk.peek();
                if (p.right == null || p.right == pVisit) {
                    //如果没有右孩子或右孩子已经访问过了，出栈
                    reslut.add(p.val);
                    //这个很重要，考虑一下只有右孩子的树，得不断的回溯
                    pVisit = p;
                    //没有新节点加入，继续进行出栈操作
                    p = null;
                    stk.pop();
                } else {
                    //如果有右孩子，右孩子入栈
                    pVisit = p.right;
                    stk.add(p.right);
                    p = p.right;
                }
            }
        }
        return reslut;
    }
}
```