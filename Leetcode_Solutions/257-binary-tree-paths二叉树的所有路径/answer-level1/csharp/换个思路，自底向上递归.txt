自底向上：

```
 public IList<string> BinaryTreePaths(TreeNode root) {
        if(root==null){
            return new List<string>();
        }
        if(root.left==null&&root.right==null){
            return new List<string>{root.val.ToString()};
        }
        var list=BinaryTreePaths(root.left) as List<string>;
        list.AddRange(BinaryTreePaths(root.right));
        for(var i=0;i<list.Count;i++){
            list[i]=root.val+"->"+list[i];
        }
        return list;
    }
```

自上而下：
```
 public IList<string> BinaryTreePaths(TreeNode root) {
        var list=new List<string>();
        BinaryTreePath(root,"",list);
        
        return list;
    }
    void BinaryTreePath(TreeNode root,string path,List<string> list){
        if(root==null){
            return;
        }
        if(!string.IsNullOrEmpty(path)){
            path=$"{path}->";
        }
        path=$"{path}{root.val}";
        if(root.left==null&&root.right==null){
            list.Add(path);
            return;
        }
        else{
            BinaryTreePath(root.left,path,list);
            BinaryTreePath(root.right,path,list);
        }
    }
```
