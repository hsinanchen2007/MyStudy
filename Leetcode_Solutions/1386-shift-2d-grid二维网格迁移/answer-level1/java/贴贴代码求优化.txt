```
class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        List<List<Integer>>  res = new ArrayList<>();
        if(grid==null)
            return null;
        int row = grid.length;
        int col = grid[0].length;
        k = k % (row * col);
        List<Integer> temp = new LinkedList<>();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(  (i*col+j+1)>(row*col-k)  ){
                    temp.add(grid[i][j]);
                }
            }
        }
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(  (i*col+j+1)<=(row*col-k)  ){
                    temp.add(grid[i][j]);
                }
            }
        }
        int num = 0;
        for(int i = 0 ; i < row ; i++){
            List<Integer> list = new ArrayList<Integer>();
            for(int j = 0 ; j < col ; j++){
                list.add(temp.get(num++));
            }
            res.add(list);
        }
        return res;
    }
}
```
# 标题