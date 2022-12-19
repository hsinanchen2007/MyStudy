直接暴力DFS。

由于要返回每次的路线，因此需要维护一个额外的path集合来存储沿途走过的节点。每次搜索路过的节点都给丢到path集合中，直到遇到叶子节点了，就把这条路径表示出来存到结果集合中。

需要注意的是，在搜索完一条路后，转而去搜索其他路线时，要回溯还原现场。

```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();

    public List<String> binaryTreePaths(TreeNode root) {
        dfs(root);
        return ans;
    }

    private void dfs(TreeNode root) {
        if(root == null) {
            return;
        }
        path.add(root.val);
        if(root.left == null && root.right == null) {
            StringBuilder temp = new StringBuilder();
            for(int i = 0; i < path.size(); i++) {
                temp.append(path.get(i));
                if(i != path.size() - 1) {
                    temp.append("->");
                }
            }
            ans.add(temp.toString());
        }
        dfs(root.left);
        dfs(root.right);
        path.remove(path.size() - 1);
    }
}
```