```
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int bigest = 0;

        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){

                if(grid[i][j]== 1){
                    grid[i][j] = 0;
                    int[] start = new int[]{i,j};

                    Queue<int[]> q = new LinkedList<>();
                    q.add(start);

                    int island = 0;

                    while(!q.isEmpty()){
                        int[] cur = q.poll();

                        island++;

                        //left
                        if(cur[0]-1>-1){
                            int row = cur[0]-1;
                            int col = cur[1];
                            addNext(row, col, grid, q);
                        }

                        //top
                        if(cur[1]-1>-1){
                            int row = cur[0];
                            int col = cur[1]-1;
                            addNext(row, col, grid, q);
                        }

                        //right
                        if(cur[0]+1<grid.length){
                            int row = cur[0]+1;
                            int col = cur[1];
                            addNext(row, col, grid, q);
                        }

                        //bottom
                        if(cur[1]+1<grid[0].length){
                            int row = cur[0];
                            int col = cur[1]+1;
                            addNext(row, col, grid, q);
                        }
                    }

                    System.out.println("island " + island);
                    bigest = Math.max(island, bigest);
                }
            }
        }

        return bigest;
    }

    private void addNext(int row, int col,int[][] grid, Queue<int[]> q){
        int[] next = new int[]{row, col};
        boolean land = grid[row][col] == 1;
        if(land){
            q.add(next);
            grid[row][col] = 0;
        }
    }
}
```