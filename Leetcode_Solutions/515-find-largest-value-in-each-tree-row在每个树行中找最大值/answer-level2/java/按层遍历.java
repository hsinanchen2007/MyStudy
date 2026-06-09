层次遍历，对每行找到最大值
然后结束内循环，对这一层的处理时，把这一层的max加入要返回的数组中
```
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if(root == null)
            return res;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            int cnt = queue.size();
            int max = Integer.MIN_VALUE;
            //for 内为一层循环，for内写对一层循环的操作
            for(int i = 0; i < cnt; i++){
                TreeNode tmp = queue.poll();
                max =Math.max(max, tmp.val);
                if(tmp.left != null){
                    queue.add(tmp.left);
                }
                if(tmp.right != null){
                    queue.add(tmp.right);
                }
            }
            //内层for循环结束，结束了一行，外层while ，处理下一行（下一行最大值）
            res.add(max);
        }
        return res;
    }
}
```
