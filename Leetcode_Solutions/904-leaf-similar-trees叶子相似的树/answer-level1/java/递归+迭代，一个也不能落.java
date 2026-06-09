递归大法好
```java
public class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        } else if (root1 == null) {
            return false;
        } else if (root2 == null) {
            return false;
        }

        List<Integer> res1 = new ArrayList<>();
        preOrder(root1, res1);
        List<Integer> res2 = new ArrayList<>();
        preOrder(root2, res2);
        return res1.equals(res2);
    }

    private void preOrder(TreeNode node, List<Integer> list) {
        if (node == null) {
            return;
        }
        preOrder(node.left, list);
        if (node.right == null && node.left == null) {
            list.add(node.val);
        }
        preOrder(node.right, list);
    }
}
```
迭代也不能落下
```java
public class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) {
            return true;
        } else if (root1 == null) {
            return false;
        } else if (root2 == null) {
            return false;
        }

        List<Integer> res1 = new ArrayList<>();
        List<Integer> res2 = new ArrayList<>();

        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(root1);
        stack2.push(root2);
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            if (!stack1.isEmpty()) {
                root1 = stack1.pop();
                if (root1.right != null) {
                    stack1.push(root1.right);
                }
                if (root1.left != null) {
                    stack1.push(root1.left);
                }
                if (root1.right == null && root1.left == null) {
                    res1.add(root1.val);
                }
            }
            if (!stack2.isEmpty()) {
                root2 = stack2.pop();
                if (root2.right != null) {
                    stack2.push(root2.right);
                }
                if (root2.left != null) {
                    stack2.push(root2.left);
                }
                if (root2.right == null && root2.left == null) {
                    res2.add(root2.val);
                }
            }
        }
        return res1.equals(res2);
    }
}
```