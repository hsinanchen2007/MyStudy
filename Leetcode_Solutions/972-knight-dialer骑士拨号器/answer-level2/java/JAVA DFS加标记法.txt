```
class Solution {
   int[][] xy = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    public int knightDialer(int N) {
        char[][] grid = {{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'#','0','#'}};

        int count = 0;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                count = (count +DFS(grid, i, j, N,map))%1000000007;
            }
        }
        return count;
    }

    private int DFS(char[][] grid, int startX, int startY, int n, Map<String,Integer> map) {
        if (grid[startX][startY]=='#') {
            return 0;
        }else if (n == 1 ) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < xy.length && n > 1; i++) {
            int x = startX + xy[i][0];
            int y = startY + xy[i][1];
            if (x >= 0 && x < 4 && y >= 0 && y < 3 && grid[x][y] != '#') {
                String key = x+"_"+y+"_"+(n -1);
                int currentCount = 0;
                if (map.get(key)!=null) {
                    currentCount = map.get(key);
                }else {
                    currentCount = DFS(grid, x, y, n - 1,map);
                    map.put(key, currentCount%1000000007);
                }
                count = (count + currentCount)%1000000007;
            }
        }
        return count%1000000007;
    }
}
```
