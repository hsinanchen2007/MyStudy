## 方法1 递归

```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        helper(root, list);
        return list;
    }

    public void helper(TreeNode node, List<Integer> res) {
        if (node != null) {
            res.add(node.val);
            helper(node.left, res);
            helper(node.right, res);
        }
    }
}
```

## 方法2 非递归

非递归的方法用stack 的方式来解。

循环结束条件是stack 不为空，或者树不为空。

- stack不为空，代表遍历过根节点
- root不为空，代表可以继续遍历左子树.

```java
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();        
        if (root == null) {
            return list;
        }
        Stack<TreeNode> stack = new Stack<>();
        while (!stack.isEmpty() || root != null) {
            //  这里代表还有左子树, 注意是while循环.
            while (root != null) {
                list.add(root.val);
                stack.add(root);
                root = root.left;                
            }
            // 左子树为null, 这时候开始遍历右子树.
            if (!stack.isEmpty()) {
                root = stack.pop();
                root = root.right;
            }
        }
        return list;
    }
}
```

知乎：[Leetcode名企之路](https://www.zhihu.com/people/ludaifei/activities)