#### DFS 迭代解法如下：
```java
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) return list;
        List<Integer> path = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();

        int pathSum = 0;
        TreeNode lastVisited = null;
        TreeNode curr = root;
        while (curr != null || !s.isEmpty()){
            // 1. 遍历搜索左边的节点，一直到叶子节点
            while (curr != null){
                // 将节点压入栈中，等待后续的处理
                s.push(curr);
                // 将当前的节点加入当前的路径中
                path.add(curr.val);
                // 累计计算当前 path 的总和
                pathSum += curr.val;
                curr = curr.left;
            }
            // 2. 访问左节点的右子树
            // 先拿到左节点，这里使用 peek() 的原因：
            //  如果这个左节点有右子树的话，我们就不用再一次 push 到栈中
            curr = s.peek();
            // 条件：有右子树，并且右子树还没有访问过
            if (curr.right != null && curr.right != lastVisited){
                // 访问右子树
                curr = curr.right;
                // 跳出外面的循环，来处理当前左节点的右子树
                continue; 
            }
            // 3. 检查是否符合路径和的条件：
            // 节点的左右子节点都为 null，并且路径总和等于目标值 sum
            if (curr.left == null && curr.right == null && pathSum == sum){
                // 当前路径符合条件，加入到返回结果中
                // 这里要重新 new 一个 ArrayList 的原因：
                // 因为后面需要对原先的 ArrayList 做删除操作
                list.add(new ArrayList<Integer>(path));
            }
            // 出栈当前的节点，因为已经处理完了
            s.pop();
            // 标记当前节点已经被访问
            lastVisited = curr;
            // 当前路径总和减去当前的节点值
            pathSum -= curr.val;
            // 当前路径中删除掉最后一个节点(也就是当前节点)
            path.remove(path.size() - 1);
            // 将当前的节点设置为 null，这是为了下次循环的时候从栈中拿到节点来进行处理
            curr = null;
        }
        return list;
    }
}
```

#### DFS 递归解法
```java
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) return list;
        List<Integer> path = new ArrayList<>();
        dfs(root, sum, list, path);
        return list;
    }

    private void dfs(TreeNode node, int target, 
                        List<List<Integer>> ans, List<Integer> path) {
        if (node == null) return;
        path.add(node.val);
        if (node.left == null && node.right == null && target == node.val) {
            ans.add(new ArrayList<>(path));
        }
        dfs(node.left, target - node.val, ans, path);
        dfs(node.right, target - node.val, ans, path);
        // 回溯
        path.remove(path.size() - 1);
    }
}
```