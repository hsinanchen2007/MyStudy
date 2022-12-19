```
public class Solution {
    public bool LeafSimilar(TreeNode root1, TreeNode root2) {
        
        List<int> node1 = new List<int>();
        List<int> node2 = new List<int>();

        
        FindLeaf(root1, node1);
        FindLeaf(root2, node2);
        
        if(node1.Count==node2.Count){
        
            for(int i=0;i<node1.Count;i++){
                if(node1[i]!=node2[i]) return false;
            }
            return true;
            
        }else{
            return false;
        }
        
    }
    
    public void FindLeaf(TreeNode node, List<int> leafs){
        if(node==null) return;
        
        if(node.left==null&&node.right==null) leafs.Add(node.val);
        
        if(node.left!=null)FindLeaf(node.left,leafs);
        if(node.right!=null) FindLeaf(node.right,leafs);
        

    }
}
```
