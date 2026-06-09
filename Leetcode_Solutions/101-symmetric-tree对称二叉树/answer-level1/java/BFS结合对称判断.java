```
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
            return true;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while(!queue.isEmpty()){
            List<Integer> level_item = new ArrayList<>();
            int level_len = queue.size();
            for(int i=0; i< level_len; i++){
                TreeNode node = queue.remove();
                if(node.left != null){
                    queue.add(node.left);
                    level_item.add(node.left.val);
                }else{
                    //随便用-1表示null
                    level_item.add(-1);
                }

                if(node.right != null){
                    queue.add(node.right);
                    level_item.add(node.right.val);
                }else{
                    level_item.add(-1);
                }
            }
            if(!isSymmetric(level_item)){
                
                return false;
            }
            
        }
        return true;
        
    }

    private boolean isSymmetric(List<Integer> list){
        
        int len = list.size();
        for(int i=0; i< len/2;i++){
            if(list.get(i) != list.get(len-i-1)){
                return false;
            }
        }
        return true;
    }
}
```
