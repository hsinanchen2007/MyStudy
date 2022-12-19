### 解题思路
利用左右两栈来实现反向,再注意一下push的顺序就好啦

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
/**
 * 利用左右两栈来实现反向
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<List<Integer>> lists = new ArrayList<>();
        Stack<TreeNode> leftStack = new Stack<>();
        Stack<TreeNode> rightStack = new Stack<>();
        //初始化
        leftStack.push(root);
        while (!leftStack.isEmpty() || !rightStack.isEmpty()) {
            //接受左栈的数
            if (!leftStack.isEmpty()) {
                List<Integer> listLeft = new ArrayList<>();
                //把左栈吐完，先左节点后右节点
                while (!leftStack.isEmpty()) {
                    TreeNode node = leftStack.pop();
                    listLeft.add(node.val);
                    //注意push的顺序
                    if (node.left != null) {
                        rightStack.push(node.left);
                    }
                    if (node.right != null) {
                        rightStack.push(node.right);
                    }
                }
                lists.add(listLeft);
            }
            if (!rightStack.isEmpty()) {
                List<Integer> listRight = new ArrayList<>();
                //把右栈吐完，先右节点后左节点
                while (!rightStack.isEmpty()) {
                    TreeNode node = rightStack.pop();
                    listRight.add(node.val);
                    //注意push的顺序
                    if (node.right != null) {
                        leftStack.push(node.right);
                    }
                    if (node.left != null) {
                        leftStack.push(node.left);
                    }
                }
                lists.add(listRight);
            }
        }
        return lists;
    }
}
```