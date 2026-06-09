### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
//常规
    public int deepestLeavesSum(TreeNode root) {
        List<TreeNode> old = new ArrayList<>();
        old.add(root);
        while(true){
            List<TreeNode> cur = new ArrayList<>();
            for(TreeNode node:old){
                if(node.left!=null) cur.add(node.left);
                if(node.right!=null) cur.add(node.right);
            }
            if(cur.size() == 0) break;
            old.clear();
            old = cur;
        }
        int res = 0;
        for(TreeNode node:old) 
            res+=node.val;
        return res;
    }
//优化
    int level = 1;
    int sum = 0;
    public int deepestLeavesSum(TreeNode root) {
        dfs(root,1);
        return sum;
    }
    private void dfs(TreeNode root,int deep){
        if(root.left!=null) dfs(root.left,deep+1);
        if(root.right!=null) dfs(root.right,deep+1);
        if(deep < level) return;
        if(deep == level) 
            sum+=root.val;
        else{
            level = deep;
            sum = root.val;
        }
    }
}
```