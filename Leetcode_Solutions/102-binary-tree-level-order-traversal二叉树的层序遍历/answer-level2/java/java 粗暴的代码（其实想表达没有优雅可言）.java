首先想到的是要用一个方法来处理一个数组，返回一个数组（即由上一层得到下一层，逐层计算下去）
显得有点臃肿、冗余、粗暴；最后还是通过了；优雅不是天生的吧

```
List<List<Integer>> ret;
    public List<List<Integer>> levelOrder(TreeNode root) {
        
        ret = new ArrayList<>();
        if(root == null){
            return ret;
        }
        List<List<TreeNode>> tempNode = new ArrayList<>();
        List<Integer> retTemp = new ArrayList<>();
        List<TreeNode>  start = new ArrayList<>(); 
        start.add(root);
        retTemp.add(root.val);
        ret.add(retTemp);
        while(start.size()!=0){
            tempNode.add(start);
            List<TreeNode> oneTemp = oneLevel(start);
            start = oneTemp;
        }
        return ret;
    }
    
    //通过行获得行
    public List<TreeNode> oneLevel(List<TreeNode> nodeList){
        List<TreeNode> temp = new ArrayList<TreeNode>();
        List<Integer> retTemp = new ArrayList<>();
        for(int i = 0; i< nodeList.size(); i++){
            if(nodeList.get(i).left!=null){
                temp.add(nodeList.get(i).left);
                retTemp.add(nodeList.get(i).left.val);
            }
            if(nodeList.get(i).right!=null){
                temp.add(nodeList.get(i).right);
                retTemp.add(nodeList.get(i).right.val);
            }
        }
        if(retTemp.size()>0){
             ret.add(retTemp);
        }
        return temp;
    }
```

