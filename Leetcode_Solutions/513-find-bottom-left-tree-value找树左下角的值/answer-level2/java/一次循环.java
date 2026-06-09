```
   public int findBottomLeftValue(TreeNode root) {
        List<TreeNode> list = new ArrayList();
        list.add(root);
        TreeNode node = root;
        for(int i =0;i<list.size();i++){
            node = list.get(i);              
            if(node.right !=null)
                list.add(node.right);            
            if(node.left !=null)
                list.add(node.left);        
        }
        return node.val;
    }
```
