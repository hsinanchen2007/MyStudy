### 解题思路
两个while循环 
内部一个while循环一直加左节点

### 代码

```java
import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
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
          //返回的列表
          List<Integer> list = new ArrayList<Integer>();

          //递归遍历二叉树
          //inorderTree(root, list);

          //使用栈进中序遍历
          Stack<TreeNode> stack  =  new Stack<TreeNode>();

          //保存当前的指针
          TreeNode cur = root;
          //两个while循环
          while (cur != null || !stack.isEmpty()) { 
              while (cur != null) {//循环加入左节点
                  stack.push(cur);
                  cur = cur.left;
              }
              //弹出节点
              cur = stack.pop();
              list.add(cur.val);//遍历到节点
              cur = cur.right;//此时如果为空 第一个while循环中 栈会起作用 因此不会结束循环
          }

          return list;
    }

    //递归写法 二叉树中序遍历
    private void inorderTree(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }

        //递归左节点
        if (root.left != null) {
            inorderTree(root.left, list);
        }

        //增加中间节点到list
        list.add(root.val);

        //递归右节点
        if (root.right != null) {
            inorderTree(root.right, list);
        }
    }
}
```