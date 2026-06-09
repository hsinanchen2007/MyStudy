```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> results = new ArrayList<>();
        if(root==null){
            return new ArrayList();
        }
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        TreeNode last = root;  //该行最后一个元素
        TreeNode lastn = root;  //下一行最后一个元素
        List<Integer> temp = new ArrayList<>();
        while(!queue.isEmpty()){
            TreeNode node = queue.poll();
            temp.add(node.val);
            if(node.left!=null){
                queue.add(node.left);
                lastn = node.left;
            }
            if(node.right!=null){
                queue.add(node.right);
                lastn = node.right;
            }
            if(node == last) {
                results.add(temp);
                temp=new ArrayList<>();
                last = lastn;
            }
        }
        return results;
    }
}
```
