### 解题思路
此处撰写解题思路
当当前节点的左右子树都为空时，也就是说访问到了叶子结点，那么将pre字符串保存到结果集中，如果存在左子树或右子树，则继续深度搜索，期间一直更新pre，即加上当前根节点和“->”;
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String>ret=new ArrayList<>();
        if(root==null) return ret;
        dfs(root,"",ret);
        return ret;
    }
    private void dfs(TreeNode root,String pre,List<String> ret){
        if(root==null) return;
        if(root.left==null&&root.right==null){
            pre+=root.val;
            ret.add(pre);
            return;
        }
        pre+=root.val+"->";
        dfs(root.left,pre,ret);
        dfs(root.right,pre,ret);
    }
}
```