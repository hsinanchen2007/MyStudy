# BFS
**思路: 利用BFS每次遍历一层, 而不是每次遍历一个**
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        //判空
        if (root == null) return new ArrayList<>();
        //创建结果集合与BFS队列
        List<List<Integer>> result = new LinkedList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        //开始BFS
        queue.add(root);
        while (!queue.isEmpty()) {
            //每次访问一层
            int size = queue.size();
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; i < size; ++i) {
                //典型BFS算法
                TreeNode child = queue.removeFirst();
                if (child.left != null) {
                    queue.add(child.left);
                }
                if (child.right != null) {
                    queue.add(child.right);
                }
                tmp.add(child.val);
            }
            //将该层数据放入结果集合
            result.add(tmp);
        }
        return result;
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)

# DFS
**思路: 利用参数传入level信息、结果集合, 每次利用level信息将当前节点的值加入结果集合**
采用先序遍历的DFS可以保证访问顺序与level对应, 若采用中序、后序则可以先计算层高并初始化结果集合
```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        //创建结果集合
        List<List<Integer>> result = new LinkedList<>();
        //传入第0层与结果集合
        dfs(root, 0, result);
        return result;
    }
    private void dfs(TreeNode root, int level, List<List<Integer>> result) {
        //递归出口
        if (root == null) return;
        //若当前level未访问过，则创建该层的集合
        if (level == result.size()) result.add(new LinkedList<>());
        //将当前节点加入level对应的集合中
        result.get(level).add(root.val);
        //先序遍历形式的DFS
        dfs(root.left, level + 1, result);
        dfs(root.right, level + 1, result);
    }
}

```
时间复杂度: O(n)
空间复杂度: O(n)