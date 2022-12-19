```
public IList<IList<int>> LevelOrderBottom(TreeNode root) {
        var res=new List<IList<int>>();
        var list=new List<TreeNode>{root};
        while(list.Count>0){
            var t=new List<TreeNode>();
            var line=new List<int>();
            foreach(var node in list){
                if(node!=null){
                    t.Add(node.left);
                    t.Add(node.right);
                    line.Add(node.val);
                }
            }
            if(line.Count>0){
                res.Insert(0,line);
            }
            list=t;
        }
        return res;
    }
```
