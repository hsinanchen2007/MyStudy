```
/**
1、算法思想：广度优先BFS;
2、核心思想：层层遍历，每次将周围的8个方向全遍历一遍，然后和目标位置比较，如果没有到达目标位置，就接着遍历第二层，一直循环，知道到达目标位置
   或者遍历所有位置结束；在寻找路径中，要判断8个方向中哪些方向可以通过；
3、关键步骤：遍历过的位置，要标记，不能重复遍历；
4、极端情况：传入的二维数组的长度为1或者为0；
*/
class Solution {
   public int shortestPathBinaryMatrix(int[][] grids) {
       int n=grids.length; int m=grids[0].length;
       //极端情况
       if(grids[0][0]==1 || grids[n-1][m-1]==1) return -1;
       if(n==1) return 1;
       //创建8个方向的二维数组
       int[][] direction={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
       //创建一个队列，存放当前位置
       Queue<int[]> queue=new LinkedList<>();
       //刚开始的位置为（0,0）
       queue.add(new int[]{0,0});
       //创建一个记录路径长度的变量
       int pathLength=0;  

       //开始遍历每一个位置      
       while(!queue.isEmpty()){
            /**
            本次循环的作用，更新size，也就是更新queue中的元素，由当前层节点调到下一层节点
            */
            //到当前位置，也就是每到一个新位置，则给路径+1，
            pathLength++;
            int size=queue.size();
            while(size-- >0){ 
                /**
                此循环首先将当前位置从queue中删除（就是表示离开当前位置），遍历最近的一层节点（本题中是8个方向）遍历一遍，把每一个走得通的方向添加到queue中，
                通过size--循环（poll删除已有的位置（刚才添加的位置不算在内，因为size定义在循环外部，循环没有退出）），遍历已有的位置（queue中元素），当size=0时，
                表示当前层的下一层节点已经遍历结束，并且把走的通的节点添加到queue中，同时把当前层节点已经删除完毕;
                */              
                int[] current=queue.poll();//将当前位置从队列中删除，同时返回给current
                int cr=current[0];
                int cc=current[1];
                grids[cr][cc]=1;//遍历过的位置标记为1，可以避免重复遍历
                //遍历当前位置的8个方向，如果可以走通，就添加到queue中,此循环实现了找可行路径功能
                for(int[] d:direction){              
                    int nr=cr+d[0];
                    int nc=cc+d[1];
                    if(nr<0 || nr>=n || nc<0 || nc>=m || grids[nr][nc]==1){
                        continue;
                        /**
                        这五种情况下都走不通，nr<0表示在grid[][0]这一列向做走；nr>=n，表示在grids[n-1][]这一行向下走，nc同理；
                        grids[nr][nc]==1，表示这是阻塞，走不通
                        */
                    }
                    if(nr==n-1 && nc==m-1){ //表示到终点了
                        return pathLength+1;        
                    } 
                    queue.add(new int[]{nr,nc});                               
                }             
            }         
       }
       return -1;
   }

}
```
