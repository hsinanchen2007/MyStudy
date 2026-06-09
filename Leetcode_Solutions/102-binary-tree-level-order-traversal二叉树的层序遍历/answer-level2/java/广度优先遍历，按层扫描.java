BFS的模板方法
1、存放在队列或者链表中；
2、循环链表，pop当前节点；
3、判断是否被访问过（图）；
4、判断是否存在子节点；
```
class Solution {
    //广度优先搜索（BFS） 按层扫描
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList();
        if(root == null){
            return res;
        }
        //将节点存放链表
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        //循环，列表不为null
        while(!queue.isEmpty()){
            int levelSize = queue.size();
            //当前层集合
            List<Integer> current_level = new ArrayList<>();
            //循环判断
            for(int i = 0;i<levelSize;i++){
                //删除当前节点
                TreeNode currentNode = queue.poll();
                //加到当前层
                current_level.add(currentNode.val);
                //判断是否有子节点，依次添加到链表
                if(currentNode.left != null){
                    queue.add(currentNode.left);
                }
                if(currentNode.right != null){
                    queue.add(currentNode.right);
                }
            }
            //添加返回值
            res.add(current_level);
        }
        return res;
    }

    //深度优先搜索（DFS） 递归方式
}
```
