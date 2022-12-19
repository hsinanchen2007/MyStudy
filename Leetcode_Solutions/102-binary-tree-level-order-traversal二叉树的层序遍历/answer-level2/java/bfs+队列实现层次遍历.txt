```
class Solution {
    //使用bfs遍历实现二叉树层次遍历
    public List<List<Integer>> levelOrder(TreeNode root) {
        //创建一个集合中对象是集合的集合
        List<List<Integer>> levels = new ArrayList<>();
        //判空
        if(root == null){
            return levels;
        }
        //创建一个队列存放节点
        Queue<TreeNode> queue = new LinkedList<>();
        //将根节点入队
        queue.add(root);
        //如果队列不为空进入循环
        while(!queue.isEmpty()){
            //用于存放节点的val
            List<Integer> li = new ArrayList<>();
            //记录每一层的节点数
            int size = queue.size();
            for(int i = 0;i < size;i++){
                //记录当前节点
                TreeNode temp = queue.poll();
                li.add(temp.val);
                //向左迭代
                if(temp.left != null){
                    queue.add(temp.left);
                }
                //向右迭代
                if(temp.right != null){
                    queue.add(temp.right);
                }
            }
            levels.add(li);
        }
        return levels;
    }
}
```
