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
     List<List<Integer>> lists=new ArrayList<>();

    public void  dfs(TreeNode root,int level){
        if (root==null)
            return;
        if (level==lists.size()){
            ArrayList<Integer> list = new ArrayList<>();
            lists.add(list);
        }
        if ((level&1)==1){
            //奇数
            lists.get(level).add(0,root.val);
        }else{
            //偶数
            lists.get(level).add(root.val);
        }

        dfs(root.left,level+1);
        dfs(root.right,level+1);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        dfs(root,0);
        return lists;
    }
}
```