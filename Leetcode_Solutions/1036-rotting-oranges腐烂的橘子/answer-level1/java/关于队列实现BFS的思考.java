### 解题思路
一开始的时候只是想到用队列，然后最后倒是实现了用队列找到一个个腐烂的桔子，并且去找到周围的桔子并感染，还使用flag来控制“这一颗桔子有没有感染其他桔子”，但是忽略了一个问题，就是如何控制“层次”，最后搜了一下普遍怎么用队列表示BFS的方法后，知道要用当前队列的长度来控制这个“层次”。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
                Queue<Pair<Integer, Integer>> queue=new LinkedList<>();
        int l=grid.length;
        int w=grid[0].length;

        int sum=0; //存储所有为1的有多少个

        for(int i =0;i<l;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]==2){
                    queue.add(new Pair(i,j));
                }
                if(grid[i][j]==1){
                    sum++;
                }
            }
        }

        int dir[][]={{-1,0},{0,1},{1,0},{0,-1}};
        int time=0;
        while(!queue.isEmpty()){
            boolean flag=true;
            int size=queue.size();
            for(int j=0;j<size;j++){    //如果不用这里的size，那么就无法控制BFS中的层次了，之前就是这里没有加size，所以导致一直出错，导致出现的问题是一个点一个点来搜索，所以增加了一些时间。
                            Pair p=queue.poll();
            int x= (int) p.getKey();
            int y= (int) p.getValue();
            
            for(int i=0;i<4;i++){
                int x0 = x + dir[i][0];
                int y0=y+dir[i][1];
                if(x0<0 || y0<0 || x0>=l || y0>=w){
                    continue;
                }
                if (grid[x0][y0]==1){
                    flag=false;
                    sum--;
                    grid[x0][y0]=2;
                    queue.add(new Pair(x0,y0));
                }  
            }
            }

            if(flag==false){
                    ++time;
                }
        }
        if(sum==0){
            return time;
        }
        else{
            return -1;
        }
    }
}
```