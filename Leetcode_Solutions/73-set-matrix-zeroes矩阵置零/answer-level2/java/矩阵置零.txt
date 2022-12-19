```
    public void setZeroes(int[][] matrix) {
        if(matrix.length == 0) return;
        Set<Integer> cols = new HashSet<>();
        Set<Integer> rows = new HashSet<>();
        
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    cols.add(j);
                    rows.add(i);
                }
            }
        }
        
        
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                if(cols.contains(j) || rows.contains(i))
                    matrix[i][j] = 0;
            }
        }
        
    }
```
