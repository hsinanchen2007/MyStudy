```
public TreeNode increasingBST(TreeNode root) {
        if(root == null) return null;
        List<Integer> nodeList = new ArrayList<>();
        midOrder(root,nodeList);
        TreeNode preNode = new TreeNode(nodeList.get(0));//取第一个
        preNode.left = null;
        root = preNode;
        for(int i=1;i<nodeList.size();i++){
            TreeNode aftNode = new TreeNode(nodeList.get(i));
            aftNode.left = null;
            preNode.right = aftNode;
            preNode = aftNode;
        }
        //最后
        preNode.right = null;
        return root;
    }
    
    public void midOrder(TreeNode root,List<Integer> list){
        if(root != null){
            midOrder(root.left,list);
            list.add(root.val);
            midOrder(root.right,list);
        }
    }
```
