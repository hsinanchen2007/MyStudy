嗯，递归
 



    public  List<List<Integer>>  levelOrder(Treenode root){
      List<List<Integer>>  list=new ArrayList<List<Integer>>();
        depth(root,1,list);
        return  list;
    }
    public void depth(Treenode root, int depth, List<List<Integer>> list){
        if(root==null){
            return ;
        }
        if(depth>list.size())
            list.add(new ArrayList<Integer>());
            list.get(depth-1).add(root.val);
            depth(root.left,depth+1,list);
            depth(root.right,depth+1,list);

        
    }

}
