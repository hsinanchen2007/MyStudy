### 解题思路
层次遍历第三版本：要求按照之字形输出结果！！！
需要借助两个栈，第一个栈的结果遍历时，将其左右节点按照先左后右的顺序压栈；第二个栈反之即可。
另外注意！！！将出栈结果放进一个list中，list大于不是0则将其添加在result结果集合中。

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<List<Integer>> result = new ArrayList<>();
        Stack<TreeNode> left = new Stack<TreeNode>();
        Stack<TreeNode> right = new Stack<TreeNode>();
        left.push(root);

        while (!left.isEmpty()) {
            List<Integer> list1 = new ArrayList<Integer>();
            while (!left.isEmpty()) {
                TreeNode tmp = left.pop();
                list1.add(tmp.val);
                if (tmp.left != null) {
                    right.push(tmp.left);
                }
                if (tmp.right != null) {
                    right.push(tmp.right);
                }
            }
            result.add(list1);

            List<Integer> list2 = new ArrayList<Integer>();
            while (!right.isEmpty()) {
                TreeNode tmp = right.pop();
                list2.add(tmp.val);
                if (tmp.right != null) {
                    left.push(tmp.right);
                }
                if (tmp.left != null) {
                    left.push(tmp.left);
                }
            }
            if (list2.size() == 0) {
                break;
            }
            result.add(list2);
        }

        return result;
    }
}
```