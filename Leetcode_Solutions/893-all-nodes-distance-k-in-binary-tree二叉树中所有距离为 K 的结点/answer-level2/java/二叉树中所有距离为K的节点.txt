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
    //注意：本题中DFS的顺序可以从子节点向根节点搜索，因此可以用树转图的思想进行深搜，采用Map记录每个节点的父节点
    private Map<TreeNode,TreeNode> parents=new HashMap<>();
    private Set<TreeNode> used=new HashSet<>();
    private TreeNode targetNode;

    //找到目标节点后以目标节点为开始位置相三个方向蔓延 
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
       find(root,null,target);
       List<Integer> res=new LinkedList<>();
       dfs(targetNode,res,K);
       return res; 
    }

    private void find(TreeNode root,TreeNode parent,TreeNode target)
    {
        if(root==null)
            return ;
        if(root.val==target.val)
        {
            targetNode=root;
        }
        parents.put(root,parent);  //不管找没找到都将这个键值对放到哈希表中存储
        find(root.left,root,target);
        find(root.right,root,target);
    }

    private void dfs(TreeNode root,List<Integer> collector,int distance){
        if(root!=null&&!used.contains(root))
        {
            //标记为已经访问
            used.add(root);
            if(distance<=0){
                collector.add(root.val);
                return;
            }
            dfs(root.left,collector,distance-1);
            dfs(root.right,collector,distance-1);
            dfs(parents.get(root),collector,distance-1);
        }
    }
}
```