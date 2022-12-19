```
public List<Double> averageOfLevels(TreeNode root) {
        List<Double> resList=new ArrayList<>();
        if(root==null)return resList;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            int count=queue.size();//记录当前队列长度。为什么记录？因为执行if以后，队列长度变了，和之前的长度一致。
            double sum=0;
            for(int i=0;i<count;i++){
                TreeNode node=queue.poll();//防止弹出后丢失，因为下面还要用到弹出的结点
                sum+=node.val;
                if(node.left!=null){
                    queue.add(node.left);
                }
                if(node.right!=null){
                    queue.add(node.right);
                }
            }
            resList.add(sum/count);
        }
        return resList;
    }
```
    
    
![TIM截图20191124155448.png](https://pic.leetcode-cn.com/0e7697f2baf4ae4e1b8c55b3dcb1762c2621aff0896c271b2a4a900b5d817e79-TIM%E6%88%AA%E5%9B%BE20191124155448.png)

