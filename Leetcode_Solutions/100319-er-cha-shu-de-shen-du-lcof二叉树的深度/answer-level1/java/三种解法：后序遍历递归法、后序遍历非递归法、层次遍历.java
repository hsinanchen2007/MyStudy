【方法一：后序遍历递归法】
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :45.1 MB, 在所有 Java 提交中击败了100.00%的用户
```
class Solution {
    public int maxDepth(TreeNode root) {
        return root == null ? 0 : Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}
```

【方法二：后序遍历非递归法】
执行用时 :5 ms, 在所有 Java 提交中击败了5.88%的用户
内存消耗 :44 MB, 在所有 Java 提交中击败了100.00%的用户
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode lastVisit = root;
        TreeNode top;
        int res = 0;
        while (!stack.isEmpty()) {
            res = Math.max(res, stack.size());
            top = stack.peek();
            if (top.left != null && lastVisit != top.left && lastVisit != top.right) {
                stack.push(top.left);
            } else if (top.right != null && lastVisit != top.right) {
                stack.push(top.right);
            } else {
                lastVisit = stack.pop();
            }
        }
        return res;
    }
}
```


【方法三：层次遍历】
执行用时 :2 ms, 在所有 Java 提交中击败了5.88%的用户
内存消耗 :46.3 MB, 在所有 Java 提交中击败了100.00%的用户
```
class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Deque<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        TreeNode levelLast = root;
        TreeNode visit;
        int depth = 0;
        while(!queue.isEmpty()) {
            visit = queue.poll();
            if (visit.left != null) {
                queue.offer(visit.left);
            }
            if (visit.right != null) {
                queue.offer(visit.right);
            }
            if (visit == levelLast) {
                levelLast = queue.peekLast();
                ++depth;
            }
        }
        return depth;
    }
}
```
