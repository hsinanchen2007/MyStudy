```
public IList<IList<int>> LevelOrder(Node root) {
        var res=new List<IList<int>>();
        if(root==null){
            return res;
        }
        
        var list=new List<Node>{root};
        
        while(list.Count>0){
            var t=new List<Node>();
            var line=new List<int>();
            foreach(var item in list){
                
                if(item!=null&&item.children!=null){
                    line.Add(item.val);
                    t.AddRange(item.children);
                }
            }
            res.Add(line);
            list=t;
        }
        return res;
    }
```
