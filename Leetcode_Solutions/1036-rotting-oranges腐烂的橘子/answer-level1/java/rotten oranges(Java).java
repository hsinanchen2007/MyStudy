广度优先，队列遍历
```
 public int orangeRotting(int[][] grid)
    {
        int count=0; //标记时间
        int fresh=0; //标记新鲜水果
        int[] drow = new int[]{-1,0,1,0};
        int[] dcol = new int[]{0,-1,0,1};
        Queue<int[]> queue= new LinkedList<>();
        //分离新鲜水果和烂水果
        for(int i=0;i<grid.length;i++)
        {
            //列
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j]==2) {
                    queue.add(new int[]{i, j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
     //   System.out.println(fresh);
        while(!queue.isEmpty()&&fresh!=0){
            int queues=queue.size();
            for(int i=0;i<queues;i++)
            {
           //     System.out.println("队列大小为："+queue.size());
                int[]a=queue.poll();
            //    System.out.println("出栈的为："+a[0]+":"+a[1]);
                for(int k=0;k<4;k++)
                {
                    int row_n=a[0]+drow[k];
                    int col_n=a[1]+dcol[k];
                    System.out.println(row_n+":"+col_n);
                    if(0<=row_n&&row_n<grid.length&&0<=col_n&&col_n<grid[0].length&&grid[row_n][col_n]==1){
                        grid[row_n][col_n]=2;
                        queue.add(new int[]{row_n,col_n});
                        fresh--;
                    }
                }
            }

            count++;
          //  System.out.println(count+"fresh is "+fresh);
        }
        if(fresh!=0)
            return -1;
        else
            return count;
    }
```
