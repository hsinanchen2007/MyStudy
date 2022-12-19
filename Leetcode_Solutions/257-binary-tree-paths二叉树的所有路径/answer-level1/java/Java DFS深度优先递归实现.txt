核心思想：
（1）递归遍历；
（2）使用path变量保存每一步走的路；

```
public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        dfs(root, "", paths);
        return paths;
    }

    private void dfs(TreeNode node, String path, List<String> paths) {
        if (node == null) {
            // 如果是空节点，直接返回
            return;
        } else if (node.left == null && node.right == null) {
            // 如果是叶子节点，说明一条路遍历完，添加到list中，结束递归
            path += node.val;
            paths.add(path);
            return;
        }
        // 如果不是叶子节点，继续深度递归遍历
        path = path + node.val + "->";
        dfs(node.left, path, paths);
        dfs(node.right, path, paths);
    }
```
