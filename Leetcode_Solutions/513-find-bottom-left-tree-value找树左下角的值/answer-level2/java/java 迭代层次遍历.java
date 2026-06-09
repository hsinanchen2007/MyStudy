```
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        //最后一层的最左边
        //迭代层次遍历
        List<List<TreeNode>> node=new ArrayList<>();
        List<TreeNode> ss=new ArrayList<>();
        ss.add(root);
        node.add(ss);
        int res=0;
        while(true){
            List<TreeNode> list=new ArrayList<>();
            for(TreeNode n:node.get(res)){
                if(n.left!=null)
                   list.add(n.left);
                   if(n.right!=null)
                   list.add(n.right);
            }
            if(list.size()==0){
               break;
            }
            node.add(list);
            res++;
        }
        return node.get(node.size()-1).get(0).val;
    }
}
```
