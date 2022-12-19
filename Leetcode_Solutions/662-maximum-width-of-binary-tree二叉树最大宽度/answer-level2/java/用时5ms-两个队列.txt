用了两个队列：
一个队列装节点，一个队列同步装这个节点对应的位置编号，编号就是他在数组中的位置。
class Solution {
 public int widthOfBinaryTree(TreeNode root) {

        //放node的队列
        Queue<TreeNode> q=new LinkedList<>();
        //放编号的队列
        Queue<Integer> num=new LinkedList<>();
        TreeNode f;

        //装入第一行root节点
        q.offer(root);
        //装入root对应的位置序号
        num.offer(0);
        int len=1;
        //每个while会将此时q里面的节点对应的下一排的子节点取出来，放到临时队列qpause中，同时这一排对应的位置序号会放在npause中
        while (!q.isEmpty()){
            //临时放入下一排的节点信息
            Queue<TreeNode> qpause=new LinkedList<>();
            LinkedList<Integer> npause=new LinkedList<>();
            //遍历q里面的节点，将q里面节点对应的下一排节点存入临时队列中
            while(!q.isEmpty()){
                TreeNode pause=q.poll();
               int n =num.poll();
                if(pause.left!=null){
                    qpause.offer(pause.left);
                    npause.offer(n*2+1);    
                }
                if(pause.right!=null){
                    qpause.offer(pause.right);
                   npause.offer(n*2+2);
                }
            }
            int plen=0;
            //计算临时队列对应的这一排的宽度
            if(npause.size()>0){
                plen = npause.getLast()-npause.getFirst()+1;
          }          
            len=len>plen?len:plen;
            //更新队列为临时队列（下一排）
            q=qpause;
            num=npause; 
        }
        return len;



    }
}
```



