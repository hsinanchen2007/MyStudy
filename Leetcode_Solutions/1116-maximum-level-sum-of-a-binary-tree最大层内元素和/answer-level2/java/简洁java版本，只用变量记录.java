```
/**
class Solution {
    public int maxLevelSum(TreeNode root) {
        int maxsum=Integer.MIN_VALUE;
        int maxh=0;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.offer(root);
        int h=0;
        while(!queue.isEmpty()){
            h++;
            int size=queue.size();
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode cur=queue.poll();
                sum+=cur.val;
                if(cur.left!=null){
                    queue.offer(cur.left);
                }
                if(cur.right!=null){
                    queue.offer(cur.right);
                }
            }
            if(sum>maxsum){
                maxsum=sum;
                maxh=h;
            }
        }
        return maxh;
    }
}
```
