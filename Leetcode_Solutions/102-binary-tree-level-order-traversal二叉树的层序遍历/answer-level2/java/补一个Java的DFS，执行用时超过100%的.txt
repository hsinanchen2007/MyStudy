![image.png](https://pic.leetcode-cn.com/ebbcbc91442740440c6c0d7250dc1e873dafd770751543b07caa1846809a1364-image.png)

```
class Solution {
    List<List<Integer>> list = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        pre(root, 0);
        return list;
    }

    private void pre(TreeNode root, int depth){
        if (root == null) return;
        if (depth >= list.size() || list.get(depth) == null){
            list.add(new ArrayList<>());
        }
        list.get(depth).add(root.val);
        pre(root.left, depth+ 1 );
        pre(root.right, depth + 1);
    }
}
```
