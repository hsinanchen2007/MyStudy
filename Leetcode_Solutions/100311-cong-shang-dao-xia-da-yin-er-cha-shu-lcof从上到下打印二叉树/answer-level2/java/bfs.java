class Solution {
    public int[] levelOrder(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        if(root==null){
            return new int[]{};
        }
        LinkedList<TreeNode> list = new LinkedList<>();
        list.add(root);
        while(!list.isEmpty()){
            int size = list.size();
            for(int i=0;i<size;i++){
                TreeNode node = list.poll();
                results.add(node.val);
                if(node.left!=null){
                    list.add(node.left);
                }
                if(node.right!=null){
                    list.add(node.right);
                }
            }
        }   
        int[] array = new int[results.size()];
        Object[] data = results.toArray();
        int p = 0;
        for(Object o:data){
            array[p++]=(int)o;
        }
        return array;
    }
}
写的比较丑陋，大家凑活看