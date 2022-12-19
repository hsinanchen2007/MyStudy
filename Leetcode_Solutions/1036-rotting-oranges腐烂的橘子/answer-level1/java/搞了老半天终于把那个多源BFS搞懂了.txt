### 解题思路


### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};  // 表示往右左上下四个方向移动

        ArrayDeque<Integer> queue = new ArrayDeque();
        HashMap<Integer, Integer> hash = new HashMap();
        
        int row = grid.length;
        int column = grid[0].length;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(grid[i][j] == 2){
                    int code = i * column + j;  //二维坐标转为一维坐标
                    queue.add(code); //存储腐烂橘子的一维坐标
                    hash.put(code, 0);  //存储腐烂橘子的一维坐标以及对应的时间
                }
            }
        }
        
        int ans = 0;
        while(!queue.isEmpty()){
            int rotten = queue.removeFirst();
            int r = rotten/column;
            int c = rotten%column; //一维坐标重新转为二维坐标
            //遍历腐烂橘子周围四个方向
            for(int i = 0; i < 4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(0<=nc && nc<column && 0<=nr && nr<row && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    int ncode = nr * column + nc;
                    queue.add(ncode);   //将新的腐烂橘子加入腐烂队列
                    hash.put(ncode, hash.get(rotten) + 1); //保证遍历一层时间只加1
                    ans = hash.get(ncode);
                }
            }
        }
        for(int[] i: grid){
            for(int j: i){
                if(j == 1)
                    return -1;
            }
        }
        return ans;
    }
}
```