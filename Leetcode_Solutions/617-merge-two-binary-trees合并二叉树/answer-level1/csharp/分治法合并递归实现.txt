各遍历两颗树，并累加对应节点值，补齐合并后的树结构
```c# []
 public TreeNode MergeTrees(TreeNode t1, TreeNode t2) {
        
        if(t1==null&&t2==null){
            return null;
        }
        TreeNode root=new TreeNode(0);
        MergeTreesTwo(t1,root);
        MergeTreesTwo(t2,root);
        return root;
    }
    
    void MergeTreesTwo(TreeNode t1, TreeNode t2){
        if(t1==null){
            return;
        }
        t2.val+=t1.val;
        if(t1.left!=null&&t2.left==null){
            t2.left=new TreeNode(0);
        }
        if(t1.right!=null&&t2.right==null){
            t2.right=new TreeNode(0);
        }
        MergeTreesTwo(t1.left,t2.left);
        
        MergeTreesTwo(t1.right,t2.right);
    }
```
