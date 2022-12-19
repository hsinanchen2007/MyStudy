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
    List<List<Integer>> res = new ArrayList();
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null){
            return res;
        }
        BFS(root,0);
        return res;
    }
    private void BFS(TreeNode node,int level){
        if(res.size() == level){
            res.add(new ArrayList<Integer>());
        }
        System.out.println("level:"+level+",val:"+node.val);
        if(level % 2 != 0){
            res.get(level).add(0,node.val);
        }else{
            res.get(level).add(node.val);
        }
        if(node.left != null){
            BFS(node.left,level+1);
        }
        if(node.right != null){
            BFS(node.right,level+1);
        }
    }
}
```