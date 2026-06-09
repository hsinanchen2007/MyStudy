
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/27
 * 
 * 解题思路: 层次遍历求平均值
 * 
 */
```
class Solution {
    List<Double> list = new ArrayList<>();
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        int num_node = 1;
        int cur_num = 1;
        double sum_node = root.val;
        queue.add(root);

        while(!queue.isEmpty()){
            cur_num = 0;
            sum_node = 0;
            for(int i = 0;i < num_node;i++){
                TreeNode q = queue.poll();
                sum_node += q.val;
                if(q.left != null){
                    cur_num += 1;
                    queue.add(q.left);
                }
                if(q.right != null){
                    cur_num += 1;
                    queue.add(q.right);
                }
            }
            list.add(sum_node/num_node);
            num_node = cur_num;
        }
        return list;
    }
}
```