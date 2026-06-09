执行用时 :2 ms, 在所有 Java 提交中击败了99.79%的用户内存消耗 :37.7 MB, 在所有 Java 提交中击败了80.03%的用户

这是一个很典型的回溯题，具体的回溯总结(模板)参见我的 `Github Search` 部分的 [Issue](https://github.com/caipengbo/AlgoEx/issues/10#issuecomment-511305780):

```Java
public class P113PathSum2 {
    // 难点：如何保存结果，回溯法！！！
    private void findPath(TreeNode root, int sum, LinkedList<Integer> path, List<List<Integer>> res) {
        if (root == null) return;
        path.add(root.val);
        if (root.left == null && root.right == null) {
            // 注意此处需要new一个新的List（自己思考一下为什么，如果不懂可以评论）
            if (root.val == sum) res.add(new LinkedList<>(path));
        }
        findPath(root.left, sum-root.val, path, res);
        findPath(root.right, sum-root.val, path, res);
        path.removeLast();
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        LinkedList path = new LinkedList();
        List<List<Integer>> res = new ArrayList<>();
        findPath(root, sum, path, res);
        return res;
    }
}
```

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

