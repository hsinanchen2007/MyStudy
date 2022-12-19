
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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null)
            return root;
        
        //用于BFS遍历树中的每个节点
        Queue<TreeNode> queue=new LinkedList<>();
        
        //用于存储每个节点对应的parent节点（模拟parent指针）
        Map<TreeNode,TreeNode> map=new HashMap<>();
        map.put(root,null);
        
        queue.add(root);
        
        //找到p和q节点即可退出循环，不用遍历整一棵树
        while(!map.containsKey(p)||!map.containsKey(q)){
            TreeNode node=queue.poll();
            if(node.left!=null){
                queue.add(node.left);
                map.put(node.left,node);
            }
            if(node.right!=null){
                queue.add(node.right);
                map.put(node.right,node);
            }
        }
        
        //用于存储P节点的所有先辈节点(包括自己)
        Set<TreeNode> set=new HashSet<>();
        
        while(p!=null){
            set.add(p);
            p=map.get(p);
        }
        
        //在p的先辈节点集合中找到q的最近先辈节点是哪一个
        while(!set.contains(q)){
            q=map.get(q);
        }
        return q;
    }
}
```