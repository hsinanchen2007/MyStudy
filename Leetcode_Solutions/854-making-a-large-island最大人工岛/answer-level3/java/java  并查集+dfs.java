**解题思路：**
使用并查集来记录每个现有的联通区域的共同parent值
dfs计算每个联通区域的面积，并且使用map记录parent与面积的对应关系

然后遍历grid，找到0值上下左右连接的联通区域，取其面积总和，最后比较得出最大值
```
class Solution {
    int[] parent;
    public void union(int a,int b){
        int aParent = find(a);
        int bParent = find(b);
        if(aParent!=bParent){
            parent[bParent] = aParent;
        }
    }
    
    public int find(int root){
        int son = root;
        while(root!=parent[root]){
            root = parent[root];
        }
        while(son!=root){
            int tmp = parent[son];
            parent[son] = root;
            son = tmp;
        }
        return root;
    }
    int[][] dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    public int largestIsland(int[][] grid) {
        int len = grid.length;
        parent = new int[55 + 50*50];
        Arrays.fill(parent,-1);
        for(int i=0 ; i<len ; i++){
            for(int j=0 ; j<len ; j++){
                parent[i*len+j] = i*len+j;
            }
        }
        Map<Integer,Integer> map = new HashMap<>();
        boolean[][] visited = new boolean[len][len];
        for(int i=0 ; i<len ; i++){
            for(int j=0 ; j<len ; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    map.put(i*len+j,dfs(grid,visited,i,j));
                }
            }
        }
        int res = 0;
        
        for(int i=0 ; i<len ; i++){
            for(int j=0 ; j<len ; j++){
                if(grid[i][j]==0){
                    Set<Integer> set = new HashSet<>();
                    for(int[] dir : dirs){
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if(x>=0 && x<len && y>=0 && y<len && grid[x][y]==1){
                            set.add(find(x*len+y));
                        }
                    }
                    int sum=0;
                    for(int key : set){
                        sum += map.get(key);
                    }
                    res = Math.max(res,sum+1);
                }
            }
        }
        return res==0 ? len*len : res;
    }
    
    public int dfs(int[][] grid,boolean[][] visited,int x,int y){
        if(x<0 || x>=grid.length || y<0 || y>=grid.length || visited[x][y] || grid[x][y]==0){
            return 0;
        }
        visited[x][y] = true;
        int res = 1;
        for(int[] dir : dirs){
            int i = x + dir[0];
            int j = y + dir[1];
            if(i>=0 && i<grid.length && j>=0 && j<grid.length && !visited[i][j] && grid[i][j]==1){
                res += dfs(grid,visited,i,j);
                union(x*grid.length+y,i*grid.length+j);
            }
        }
        return res;
    }
}
```
