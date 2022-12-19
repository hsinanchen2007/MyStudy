# 思路
- DFS遍历树，对于每个节点，维护一个列表，列表值为从根节点到该节点的路径上，从根开始，逐个减去一个节点，所得到的路径上节点值的和。

# 代码
```
private int dfs(TreeNode r, int sum, List<Integer> sumList) {
    int cur_count = 0;
    if (r != null) {
        int path_sum = 0;
        cur_count = (r.val == sum) ? 1 : 0;
        for (int i = 0; i < sumList.size(); i++) {
            // 在每条路径加上当前节点值
            path_sum = sumList.get(i) + r.val;
            if (path_sum == sum) {
                cur_count++;
            }
            sumList.set(i, path_sum);
        }
        // 当前单个节点作为路径
        sumList.add(r.val);
        // 这边要传递一个新创建的列表，不能在后续递归中修改当前列表，所以说是每个节点维护一个包含当前节点的路径的和的列表
        cur_count += dfs(r.left, sum, new ArrayList<>(sumList));
        cur_count += dfs(r.right, sum, new ArrayList<>(sumList));
    }
    return cur_count;
}

public int pathSum(TreeNode root, int sum) {
    List<Integer> pathSumList = new ArrayList<Integer>();
    return dfs(root, sum, pathSumList);
}
```

# 总结
- 时间复杂度O(n^2) (最坏) O(nlogn)(最好)
- 空间复杂度O(n^2) (最坏) O(nlogn)(最好)