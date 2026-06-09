```
public bool LeafSimilar(TreeNode root1, TreeNode root2) {
        var list1=new List<int>();
        var list2=new List<int>();
        LeafSimilar(root1,list1);
        LeafSimilar(root2,list2);
        if(list1.Count==list2.Count){
            for(var i=0;i<list1.Count;i++){
                if(list1[i]!=list2[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    void LeafSimilar(TreeNode root,List<int> list){
        if(root==null) return;
        if(root.left==null&&root.right==null){
            list.Add(root.val);
            return;
        }
        LeafSimilar(root.left,list);        
        LeafSimilar(root.right,list);
        
    }
```
