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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        _levelOrder(root,res,0);
        //对正常层序遍历结果逆序
        Collections.reverse(res);
        return res;
    }
    //正常的层序遍历
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