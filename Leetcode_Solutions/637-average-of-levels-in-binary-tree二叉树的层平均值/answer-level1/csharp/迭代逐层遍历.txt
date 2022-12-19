```
public IList<double> AverageOfLevels(TreeNode root) {
        var list=new List<TreeNode>(){root};
        var res=new List<double>();
        while(list?.Count>0){
            var t=new List<TreeNode>();
            double sum=0;
            foreach(var node in list){
                if(node.left!=null){
                    t.Add(node.left);
                }
                if(node.right!=null){
                    t.Add(node.right);
                }
                sum+=node.val;
            }
            res.Add(sum/list.Count);
            list=t;
        }
        return res;
    }
```
