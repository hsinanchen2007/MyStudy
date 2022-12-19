```
public class Solution {
    public TreeNode IncreasingBST(TreeNode root) {
        
        List<TreeNode> node = new List<TreeNode>();
        Find(root,node);
        
        for(int i =0;i<node.Count-1;i++){
            node[i].left=null;
            node[i].right = node[i+1];
        }
        
        if(node.Count!=0){
            node[node.Count-1].left = null;
            node[node.Count-1].right = null;
        }
        
        return node[0];
    }
    
    public void Find(TreeNode node,List<TreeNode> leafs){
        
        if(node==null) return;
        Find(node.left,leafs);
        leafs.Add(node);
        Find(node.right,leafs);
        
    }
}
```
