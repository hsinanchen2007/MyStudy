# 思路
   优先右子树的深度优先遍历，deepest表示目前存的最大深度
# 代码
```java
    List<Integer> ans = new ArrayList<>();
    int deepest = 0;

    public List<Integer> rightSideView(TreeNode root) {
        helper(root, 0);
        return ans;
    }

    private void helper(TreeNode root, int now) {
        if (root == null) return;
        if (now == deepest) {
            ans.add(root.val);
            deepest++;
        }
        helper(root.right, now + 1);
        helper(root.left, now + 1);
    }
```