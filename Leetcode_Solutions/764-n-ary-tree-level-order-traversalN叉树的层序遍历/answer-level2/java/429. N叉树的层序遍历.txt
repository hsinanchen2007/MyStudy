
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/10
 * 
 * 解题思路: 标准层次遍历代码
 * 
 */


```

    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> lists = new ArrayList<>();

        //空判断
        if(root == null){
            return lists;
        }

        //定义队列 并加入根节点
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        //记录当前队列的中的存在的节点个数
        int count = 1;
        while(!queue.isEmpty()){
            count = queue.size();
            List<Integer> list = new LinkedList<>();
            while(count-- > 0){
                //弹出当前节点
                Node n = queue.poll();
                list.add(n.val);
                //如果子节点为空
                if(n.children != null){
                    //将子节点加入队列 若为二叉树 则直接左右节点
                    for(int i = 0;i < n.children.size();i++){
                        queue.add(n.children.get(i));
                    }
                }
            }
            lists.add(list);
        }
        return lists;
    }

```