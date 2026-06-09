思路：分别dfs搜索两棵树，保存叶子序列，比较即可。
<br/><br/>
代码：
```
class Solution {
    List<Integer> list1 = new ArrayList<>();
    List<Integer> list2 = new ArrayList<>();
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        dfs(root1,1);
        dfs(root2,2);
        
        if (list1.size() != list2.size()) {
            return false;
        }
        
        for (int i = 0;i < list1.size();i++) {
            if (list1.get(i) != list2.get(i)) {
                return false;
            }
        }
        
        return true;
    }
    
    private void dfs(TreeNode root,int tree) {
        if (root == null) {
            return;
        }
        
        dfs(root.left,tree);
        
        if (root.left == null && root.right == null) {
            if (tree == 1) {
                list1.add(root.val);
            } else if (tree == 2) {
                list2.add(root.val);
            }
            
        }
        
        dfs(root.right,tree);
    }
}
```