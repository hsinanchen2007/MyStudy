```java

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> list=new ArrayList<>();
        inOrder(root, list);
        return create(list,0,list.size()-1);
    }
    //中序遍历获取有序节点
    void inOrder(TreeNode node, List<Integer> list){
        if(node==null) return;
        inOrder(node.left,list);
        list.add(node.val);
        inOrder(node.right,list);
    }
//建树
    TreeNode create(List<Integer> list,int left, int right){
        if(left>right) return null;
        int mid=(left+right)/2;
        TreeNode node=new TreeNode(list.get(mid));
        node.left =create(list, left,  mid-1);
        node.right=create(list, mid+1, right);
        return node;
    }
```
