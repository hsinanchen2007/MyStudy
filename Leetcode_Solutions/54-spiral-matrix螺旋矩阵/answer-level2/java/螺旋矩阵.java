空间换时间
```
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ansList = new ArrayList<>();
        if(matrix.length == 0) return ansList;
        int row = matrix.length, cols = matrix[0].length;

        int i = 0, j = 0, index = 0;
        int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};
        boolean[][] cache = new boolean[row][cols];

        for(int n=0; n<row*cols; n++){
            ansList.add(matrix[i][j]);
            cache[i][j] = true;
            i += dir[index][0];
            j += dir[index][1];
            
            if(i < 0 || i >= row || j < 0 || j >= cols || cache[i][j]){
                i -= dir[index][0];
                j -= dir[index][1];
                index =(index+1)% 4; 
                i += dir[index][0];
                j += dir[index][1]; 
            }
        }

        return ansList;
    }
```
