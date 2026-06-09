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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        _levelOrder(root,res,0);
        if(res.size()>1)
            for(int i=1;i<res.size();i=i+2)
                Collections.reverse(res.get(i));
        return res;
    }
    private void _levelOrder(TreeNode cur,List<List<Integer>> nodes,int level){
        if(cur==null)
            return;
        if(nodes.size()==level)
            nodes.add(new ArrayList<Integer>());
        nodes.get(level).add(cur.val);
        _levelOrder(cur.left,nodes,level+1);
        _levelOrder(cur.right,nodes,level+1);
    }
}
```