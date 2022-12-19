```
class Solution {
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};
    int R = 0, C = 0;
    Queue<Pair> queue = new LinkedList<Pair>();
    public int shortestBridge(int[][] A) {
        R = A.length; 
        C = A[0].length;
        boolean[][] use = new boolean[R][C];
        //DFS: 找到第一座岛屿
        for(int r = 0; r < R; r++){
            boolean flag = false;
            for(int c = 0; c < C; c++){
                if(A[r][c] == 1){
                    A[r][c] = 2;
                    dfs(r, c, A,use);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        //BFS: 找到最短路径
        while(!queue.isEmpty()){
            Pair pair = queue.poll();
            for(int k = 0; k < 4; k++){
                int nr = pair.r + dr[k];
                int nc = pair.c + dc[k];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C){
                    if(A[nr][nc] == 1){
                       return pair.depth; 
                    }else if(A[nr][nc] == 0){
                       A[nr][nc] = 2; 
                       queue.add(new Pair(nr, nc, pair.depth + 1)); 
                    }
                }
            }
        }
        return 0;
    }
    
    private void dfs(int r, int c, int[][] A,boolean[][]use){
        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && !use[nr][nc]){
                use[nr][nc] =true;
                if(A[nr][nc] == 1){
                   A[nr][nc] = 2;
                   dfs(nr, nc, A,use); 
                }else if(A[nr][nc] == 0){
                   A[nr][nc] = 2; 
                   queue.add(new Pair(nr, nc, 1)); 
                }
            }
        }
    }
    
    class Pair{
        int r;
        int c;
        int depth;
        public Pair(int r, int c, int depth){
            this.r = r;
            this.c = c;
            this.depth = depth;
        }
    }
}
```
