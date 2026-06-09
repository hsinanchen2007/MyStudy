```
class Solution {
    public int maxDistance(int[][] grid) {
        int len=grid.length;
        if(len==1) return -1;
        LinkedList<int[]> list=new LinkedList<>();
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(grid[i][j]==1) list.add(new int[]{i,j});
            }
        }
        if(list.size()==0 || list.size()==len*len) return -1;
        int times=-1;
        while(!list.isEmpty()){
            times++;
            int size=list.size();
            for(int i=0;i<size;i++){
                int[] m=list.poll();
                int a=m[0],b=m[1];
                if(a-1>=0 && grid[a-1][b]==0){
                    grid[a-1][b]=1;
                    list.offer(new int[]{a-1,b});
                }
                if(b-1>=0 && grid[a][b-1]==0){
                    grid[a][b-1]=1;
                    list.offer(new int[]{a,b-1});
                }
                if(a+1<len && grid[a+1][b]==0){
                    grid[a+1][b]=1;
                    list.offer(new int[]{a+1,b});
                }
                if(b+1<len && grid[a][b+1]==0){
                    grid[a][b+1]=1;
                    list.offer(new int[]{a,b+1});
                }
            }
        }
        return times;
    }
}
```
